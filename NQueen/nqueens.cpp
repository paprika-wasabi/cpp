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
    for (bool successor : {true, false}) {
        Node *successorNode = currentNode;
        Board successorBoard = successorNode->get_configuration();
        if (successor) {
            successorBoard.next(true);
        } else {
            successorBoard.next(false);
        }

        if (successorBoard.is_full() || !successorBoard.is_valid()) {
            if (successor) {
                bdd.connect_true(bdd.import_node(currentNode), true);
            } else {
                bdd.connect_false(bdd.import_node(currentNode), true);
            }
        } else {
            successorNode = bdd.import_node(successorBoard);
            if (successor) {
                bdd.connect_true(bdd.import_node(currentNode), true);
            } else {
                bdd.connect_false(bdd.import_node(currentNode), true);
            }
            positionToProcess.push(successorNode);
        }
    }
  }
}