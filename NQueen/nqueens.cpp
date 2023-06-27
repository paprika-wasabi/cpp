#include <fstream>
#include <stack>

#include "nqueens.hpp"
#include "board.hpp"
#include "stack.hpp"

// connect Node parent to its child (direction true or false) and pushing the
// node to the stack if needed
void NQueens::check_and_add_child(Node *parent, bool direction,
                                  std::stack<Node *> &stack) {
  // NB: this is just a helper function I found useful to have, but
  Board tempBoard;
    if (direction) {
        tempBoard = parent->if_true->get_configuration();

    } else {
        tempBoard = parent->if_false->get_configuration();
    }

    if (tempBoard.is_valid() or tempBoard.is_full()) {
        bdd.import_node(tempBoard);
    } else {
        bdd.import_node(tempBoard);

    }

}

void NQueens::construct_bdd() {
  std::stack<Node*> positionToProcess;
  Board initBoard(size);
  Node *rootNode = new Node(0, initBoard);
  positionToProcess.push(*rootNode);

  while (!positionToProcess.empty()) {
    //Board currentBoard = positionToProcess.top();
    //positionToProcess.pop();
    //Board tempBoard = rootNode->if_true->get_configuration();
    //check_and_add_child(rootNode, 0, positionToProcess);
    //check_and_add_child(rootNode, 1, positionToProcess);
  }
}