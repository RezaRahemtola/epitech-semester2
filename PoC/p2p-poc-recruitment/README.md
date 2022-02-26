# Merkle Tree Authentication

This assigment is a simple implementation of Merkle Tree usable to mimic an authentication system.

Such a system is used to authorize users to access a resource in a smart contract on Ethereum.

The goal of this assignment is to implement a Merkle Tree which contains addresses of users.

Then, the user can request a proof of inclusion of his address in the tree.

Finally, the user can verify the proof of inclusion of his address in the tree.

## Getting Started

Before starting the assignment, you should have a basic knowledge of how Merkle Tree behave.

Learn more about the data structure [here](https://brilliant.org/wiki/merkle-tree/).

Learn more about Merkle Tree Proofs [here](https://medium.com/crypto-0-nite/merkle-proofs-explained-6dd429623dc5).

## Instructions

In the MerkleTree folder, run the following command to install the required dependencies:

```bash
npm install
```

Then, run the following command to run the tests:
```bash
npx hardhat clean && npx hardhat compile && npx hardhat test
```

They should fail. Good news :)

In the `test/index.ts` file, you'll find the tests for the Merkle Tree Authentication smart contract.

Your goal is to make them pass.

You'll have to :

- Implement the `isAuthorized` function in `contracts/MerkleTreeAuth.sol`.

- Implement the `getAccounts`, `getLeafNodes` and build the proofs in the two last tests of the `test/index.ts` file.
