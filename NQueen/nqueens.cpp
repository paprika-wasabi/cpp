#include <stack>

#include "nqueens.hpp"

void NQueens::construct_bdd() {
  Stack<Node*> positionToProcess;
  Board initBoard(size);
  Node *rootNode = bdd.import_node(initBoard);
  positionToProcess.push(rootNode);

  while (!positionToProcess.empty()) {
    Node *currentNode = positionToProcess.top();
    positionToProcess.pop();


    Board tempBoardA(size);
    Node *tempNodeA;
    Board tempBoardB(size);
    Node *tempNodeB;

    tempBoardA.next(true);
    tempNodeA = bdd.import_node(tempBoardA);

    tempBoardB.next(false);
    tempNodeB = bdd.import_node(tempBoardB);



    if (tempBoardA.is_full() or !tempBoardA.is_valid()) {
        bdd.connect_true(currentNode, true);
    } else {
        bdd.import_node(tempBoardA);
        stack.push(tempNodeA);
        bdd.connect(currentNode, tempNodeA, true);
    }

    if (tempBoardB.is_full() or !tempBoardB.is_valid()) {
        bdd.connect_false(currentNode, false);
    } else {
        bdd.import_node(tempBoardB);
        stack.push(tempNodeB);
        bdd.connect(currentNode, tempNodeB, false);
    }
  }
}