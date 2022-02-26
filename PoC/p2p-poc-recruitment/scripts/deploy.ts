import { keccak256 } from "ethers/lib/utils";
import { ethers } from "hardhat";
import { MerkleTree } from "merkletreejs";

async function main() {
  // Build the merkle tree.
  const accounts = await ethers.getSigners();
  const leafNodes = accounts.map((account) => {
      keccak256(account.address);
  });
  const merkleTree = new MerkleTree(leafNodes);
  const merkleRoot = merkleTree.getHexRoot().toString();


  const MerkleTreeAuth = await ethers.getContractFactory("MerkleTreeAuth");
  const merkleTreeAuth = await MerkleTreeAuth.deploy(merkleRoot);

  await merkleTreeAuth.deployed();

  console.log("MerkleTreeAuth deployed to:", merkleTreeAuth.address);
}

main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
