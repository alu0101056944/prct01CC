/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Stack of symbols. Each transition requires a symbol to be popped from the
 * stack. It only operates with it's alphabet (or '.' char when pushing). Automata
 * checks if it is empty to know whether to continue or abort input word recognition.
 * 
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
     * Pushes a string into the stack. Throws exception if it attempts to push a
     *  character that is not on the stack alphabet.
     */
    void push(std::string symbols);

    /**
     * Pop only if symbol is on top of the stack.
     * Throws exception if stack doesn't have that char on top or if it's empty.
     */
    void pop(char symbol);

    /**
     * Used by Automata to know when to stop searching input word recognition.
     */
    bool empty();

    /**
     * Used everytime Automata needs to recognize a new word. Clears the stack
     * leaving only the initial symbol in it.
     */
    void reset();

    /**
     * When a State no longer has transitions available this function is called to
     * recover old stack symbols.
     */
    void fallback();

    /**
     * Called by Automata before applying a transition.
     */
    bool canPop(char symbol);
  private:
    std::stack<char> stack, history;
    std::string alphabet;
    char initialSym;
};

#endif
