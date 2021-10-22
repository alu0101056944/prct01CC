/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Implementation of a Stack Automata as Emptied Stack. Only accepts the input
 *  word if the stack is emptied and the whole word has been successfully read
 *  from the loading belt.
 * 
 * It accepts a given input word, stored on the loading belt, if the stack is
 * empty and the loading belt has been fully readed.
 * 
 * Defined states and transitions are used to check validity of the input word.
 * 
 * Uses a stack to read and store symbols and a loading belt to read a given
 *  input word. A current state is changed depending on the defined transitions
 * on each state, when applied.
 * 
 * Each transition requires one or none value to be read from the loading belt.
 *  Everytime the loading belt is read the header moves to the next cell, which
 *  contains a different letter from the input word.
 * 
 * Transitions also denote a symbol to be popped and a set of symbols to be pushed.
 *  When the stack gets empty the program execution is stopped, indicating that the
 *  input word isn't recognized by the automata, unless the loading belt has reached
 *  beyond the cell where the last letter of the input word is stored, in which case
 *  the word is considered recognized.
 */

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>

#include "./state.h"
#include "./symbolstack.h"
#include "./loadingbelt.h"

class Automata {
  public:
    Automata(std::string beltAlphabet, std::string stackAlphabet, char initialStackSym);

    /**
     * Returns true if inputWord is recognized by this automata.
     */
    bool validate(std::string inputWord);
  private:
    std::stack<State> stateHistory;
    SymbolStack stack;
    LoadingBelt loadingBelt;
    std::string beltAlphabet;
    std::string stackAlphabet;
    char initialStackSym;
};
#endif