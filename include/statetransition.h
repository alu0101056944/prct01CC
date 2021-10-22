/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Mainly for data storage purposes. Each state has a set of state transitions
 *  associated. Each transition contains the symbol to be read from the loading
 *  belt, the stack symbol to be popped and a set of symbols to be inserted into
 *  the stack.
 * 
 * Changes automata's loading belt and stack storage once applied.
 * 
 */

#ifndef STATETRANSITION_H
#define STATETRANSITION_H

#include <string>

class StateTransition {
  public:
    StateTransition(char beltSymbol, char stackSymbolToPop, std::string stackSymbolsToInsert,
      std::string nextState);

    char getBeltSymbol();
    char getStackSymbolToPop();
    std::string getStackSymbolsToInsert();
    std::string getNextState();
  private:
    char beltSymbol;
    char stackSymbolToPop;
    std::string stackSymbolsToInsert;
    std::string nextState;
};

#endif
