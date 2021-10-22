#include "../include/state.h"

State::State(int id, std::vector<StateTransition> transitions) : 
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
