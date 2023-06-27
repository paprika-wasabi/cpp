#include <fstream>
#include <stack>

#include "nqueens.hpp"
#include "board.hpp"
#include "stack.hpp"

// connect Node parent to its child (direction true or false) and pushing the
// node to the stack if needed
void NQueens::check_and_add_child(Node *parent, bool direction,
                                  Stack<Node *> &stack) {

}

void NQueens::construct_bdd() {
  Stack<Node*> positionToProcess;
  Board initBoard(size);
  Node *rootNode = new Node(0, initBoard);
  positionToProcess.push(rootNode);

  while (!positionToProcess.empty()) {
    Board currentBoard = positionToProcess.top()->get_configuration();
    positionToProcess.pop();
    Board tempBoard = rootNode->if_true->get_configuration();
  }
}