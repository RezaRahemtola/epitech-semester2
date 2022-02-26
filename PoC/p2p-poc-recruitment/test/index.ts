import { expect } from "chai";
import keccak256 from "keccak256";
import { ethers } from "hardhat";
import { MerkleTree } from "merkletreejs";
import { Contract } from "ethers";

describe("MerkleTreeAuth", function () {
  let contract: Contract;
  let merkleTree: MerkleTree;

  // getAccounts will return an array of accounts.
  const getAccounts = async () => {
    // You must use ethers to get the loaded accounts.
    const accs = await ethers.getSigners();
    /* I also found this :
    await ethers.provider.listAccounts();
    which directly gives the addresses. */

    return [
      accs[0].address,
      accs[1].address,
    ];
  }

  // getLeafNodes will return an array of leaf nodes.
  const getLeafNodes = (accounts: string[]) => {
    // Build the leaf nodes array using the accounts.

    // For each element of the array, we hash it using Keccak-256.
    return accounts.map(value => keccak256(value));
  }

  // buildTree will build a MerkleTree from the given array of account.
  // It returns the merkle root.
  const buildMerkelTree = async (accounts: string[]) => {
    const leafNodes = getLeafNodes(accounts);

    // Build the Merkle tree and get the Merkle tree hex root.
    merkleTree = new MerkleTree(leafNodes, keccak256, { sort: true });

    return merkleTree.getHexRoot();
  }

  it("Should deploy the contract correctly", async function () {
    // Get the accounts.
    const accounts = await getAccounts();

    // Build the merkle tree.
    const merkleRoot = await buildMerkelTree(accounts);

    // Deploy the Merkle tree authentication contract.
    const MerkleTreeAuth = await ethers.getContractFactory("MerkleTreeAuth");
    contract = await MerkleTreeAuth.deploy(merkleRoot);
    await contract.deployed();
  });

  describe("Authentication", async () => {
    it("Should authenticate a valid account", async () => {
      // Get the valid account.
      const leafUser0 = getLeafNodes((await ethers.getSigners()).map(acc => acc.address))[0];
      // Build a proof using the account.
      const proof = merkleTree.getHexProof(leafUser0);

      await expect(await contract.connect(ethers.provider.getSigner(0)).isAuthorized(proof)).to.be.true;
    });

    it("Should not authenticate an invalid account", async () => {
      // Get the invalid account.
      const leafUser2 = getLeafNodes((await ethers.getSigners()).map(acc => acc.address))[2];
      // Build a proof using the account.
      const proof = merkleTree.getHexProof(leafUser2);

      /* For a (very) long time I stuggled to make this test pass, because my getAccounts function was returning the whole array of addresses instead of
      just the 0 and 1 as it was in the original subject. Before realizing this, I modified the test to make it pass with an explanation of why I did it.
      I spent so much time on this problem (probably more than on the rest of the project itself) that I decided to leave this justification below if you wanna read it :)

      The above line with getLeafNodes was modified to make this test pass. Indeed, I changed the leaf index to be different than the one in the test below.
      I don't understand why this test should fail without doing this, I tried to modify
      the account number (between 0 and 19) in both the leaf above and the test below but my isAuthorized implementation returns true for all of them.
      This seems logical, the buildMerkelTree function gets these 20 addresses, hash them with getLeafNodes and
      then creates the MerkelTree. So when we try to check if any of these addresses is authorized with the corresponding Merkle proof,
      it can only returns true, it's if we test with mismatched address/proof or even root that isAuthorized will return false.

      As an example, the tests of the OpenZeppeling verification method werw using a proof from another Merkle tree to check for
      a return false (https://github.com/OpenZeppelin/openzeppelin-contracts/blob/release-v3.4/test/cryptography/MerkleProof.test.js lines 29-42).

      In this case, I'm using a wrong proof, not from another tree but from another account, which is making the function return false.
      */
      await expect(await contract.connect(ethers.provider.getSigner(2)).isAuthorized(proof)).to.be.false;
    });
  })
});
