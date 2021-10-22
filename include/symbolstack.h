/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Once a state transition is applied, the automata object changes the stack's
 *  contents.
 * 
 * Program execution ends when stack is empty.
 * 
 * Symbols(characters) are introduced into the stack from first index to last. So
 * instead of them being left is top, I consider them as left is bottom.
 */

#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>
#include <stack>

class SymbolStack {
  public:
    SymbolStack(char initialSym, std::string alphabet);

    /**
     * Pushes a set of chars (string). Throw exception if it attempts to push a
     *  character that is not on the stack alphabet.
     */
    void push(std::string symbols);

    /**
     * Throws exception if stack doesn't have that char on top or if it's empty.
     */
    void pop(char symbol);
    bool empty();
    void reset();
    void fallback();
    bool canPop(char symbol);
  private:
    std::stack<char> stack, history;
    std::string alphabet;
    char initialSym;
};

#endif
