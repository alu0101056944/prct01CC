/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Once a state transition is applied, the automata object changes the stack's
 *  contents.
 * 
 * Program execution ends when stack is empty.
 */

#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class Stack {
  Stack();

  void pop(string sym);
  void print();
};

#endif
