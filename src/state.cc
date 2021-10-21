#include "../include/state.h"

#include <iostream>
State::State(int id, vector<StateTransition> transitions) : 
    id(id), transitions(transitions) {}

void State::print() {
  for (int i = 0; i < transitions.size(); i++) {
    cout << transitions[i].getBeltSymbol() << " ";
    cout << transitions[i].getNextState() << " ";
    cout << " |pop: " << transitions[i].getStackSymbolToPop() << " ";
    cout << transitions[i].getStackSymbolsToInsert() << endl;
  }
}