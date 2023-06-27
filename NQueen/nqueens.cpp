#include <fstream>
#include <stack>

#include "nqueens.hpp"
#include "board.hpp"
#include "stack.hpp"

// connect Node parent to its child (direction true or false) and pushing the
// node to the stack if needed
void NQueens::check_and_add_child(Node *parent, bool direction,
                                  Stack<Node *> stack) {
    Board tempBoard;
    Node *tempNode;
    if (direction) {
        tempBoard = parent->if_true->get_configuration();
        tempNode = parent->if_true;
    } else {
        tempBoard = parent->if_false->get_configuration();
        tempNode = parent->if_false;
    }

    if (tempBoard.is_full() or !tempBoard.is_valid()) {
        bdd.import_node(tempBoard);
    } else {
        bdd.import_node(tempBoard);
        stack.push(tempNode);
    }

}

void NQueens::construct_bdd() {
  Stack<Node*> positionToProcess;
  Board initBoard(size);
  Node *rootNode = new Node(0, initBoard);
  positionToProcess.push(rootNode);

  while (!positionToProcess.empty()) {
    Board currentBoard = positionToProcess.top()->get_configuration();
    positionToProcess.pop();
    check_and_add_child(rootNode, 0, positionToProcess);
    check_and_add_child(rootNode, 1, positionToProcess);
  }
}