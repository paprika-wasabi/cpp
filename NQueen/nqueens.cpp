#include <stack>

#include "nqueens.hpp"

// connect Node parent to its child (direction true or false) and pushing the
// node to the stack if needed
void NQueens::check_and_add_child(Node *parent, bool direction,
                                  Stack<Node *> stack) {
    //Board tempBoard(size);
    //Node tempNode;
    if (direction) {
        //tempBoard.next(true);
        //tempNode = bdd.import_node(tempBoard);
    } else {
        //.next(false);
        //tempNode = bdd.import_node(tempBoard);
    }


//    if (tempBoard.is_full() or !tempBoard.is_valid()) {
//      if (direction) {
//            bdd.connect_true(parent, direction);
//       } else {
//           bdd.connect_false(parent, direction);
//        }
//
//    } else {
//        //bdd.import_node(tempBoard);
//        //stack.push(tempNode);
//        //bdd.connect(parent, tempNode, direction);
//    }

}

void NQueens::construct_bdd() {
  Stack<Node*> positionToProcess;
  Board initBoard(size);
  Node *rootNode = bdd.import_node(initBoard);
  positionToProcess.push(rootNode);

  while (!positionToProcess.empty()) {
    check_and_add_child(positionToProcess.top(), 0, positionToProcess);
    check_and_add_child(positionToProcess.top(), 1, positionToProcess);
    positionToProcess.pop();
  }
}