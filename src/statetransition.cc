#include "../include/statetransition.h"

StateTransition::StateTransition(char beltSymbol, char stackSymbolToPop,
    std::string stackSymbolsToInsert, std::string nextState) :
    beltSymbol(beltSymbol),
    stackSymbolToPop(stackSymbolToPop),
    stackSymbolsToInsert(stackSymbolsToInsert),
    nextState(nextState) {}

char StateTransition::getBeltSymbol() {
  return beltSymbol;
}

char StateTransition::getStackSymbolToPop() {
  return stackSymbolToPop;
}

std::string StateTransition::getStackSymbolsToInsert() {
  return stackSymbolsToInsert;
}

std::string StateTransition::getNextState(){
  return nextState;
}