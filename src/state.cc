#include "../include/state.h"

#include <iostream>
State::State(int id, vector<StateTransition> transitions) : 
    id(id), indexOfNextTransition(0), transitions(transitions) {}

StateTransition State::getNextTransition() {
  return transitions[indexOfNextTransition++];
}

bool State::moreTransitionsAvailable() {
  return indexOfNextTransition < transitions.size();
}

bool State::isSameState(int idOfOtherState) {
  return id == idOfOtherState;
}

State State::copy() {
  State copy(id, transitions);
  for(int i = 0; i < indexOfNextTransition; i++) {
    copy.getNextTransition();
  }
  return copy;
}

void State::print() {
  for (int i = 0; i < transitions.size(); i++) {
    cout << transitions[i].getBeltSymbol() << " ";
    cout << transitions[i].getNextState() << " ";
    cout << " |pop: " << transitions[i].getStackSymbolToPop() << " ";
    cout << transitions[i].getStackSymbolsToInsert() << endl;
  }
}