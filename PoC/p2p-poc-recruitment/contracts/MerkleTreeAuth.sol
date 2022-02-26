//SPDX-License-Identifier: Unlicense
pragma solidity ^0.8.0;

// We must import MerkleProof from OpenZeppelin to use its verification method in our contract.
import "@openzeppelin/contracts/utils/cryptography/MerkleProof.sol";

contract MerkleTreeAuth {
    // The merkle tree root.
    bytes32 public merkleRoot = 0x0;

    constructor(bytes32 _merkleRoot) {
        merkleRoot = _merkleRoot;
    }

    // The following method uses the provided proof to verify if the sender has been included in our contract.
    function isAuthorized(bytes32[] calldata _merkleProof) public view returns (bool) {
        // Create the leaf used to verify the proof.
        bytes32 leaf = keccak256(abi.encodePacked(msg.sender));

        // Using Open Zeppelin's method for the verification
        return MerkleProof.verify(_merkleProof, merkleRoot, leaf);

        // We could also do the verification manually if we had the index of the leaf
        // by rebuilding the merkle root with something like this :
        /*
        bytes32 leaf = 0x00;

        for (uint i = 0; i < _merkleProof.length; i++) {
            // The concatenation order is determined by the index :
            // if it's even, we append the current proof hash to our leaf, else it's odd so we append it to the proof hash
            if (index % 2 == 0) {
                leaf = keccak256(abi.encodePacked(leaf, _merkleProof[i]));
            } else {
                leaf = keccak256(abi.encodePacked(_merkleProof[i], leaf));
            }
            // Alternate the index between odd and even
            index = index / 2;
        }
        // We compare the resulting root with the real one, if it's the same the sender is in the contract
        return leaf == merkleRoot;
        */
    }
 }
