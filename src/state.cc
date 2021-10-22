#include "../include/state.h"

State::State(std::string stateName, std::vector<StateTransition> transitions) : 
    stateName(stateName), indexOfNextTransition(0), transitions(transitions) {}

StateTransition State::getNextTransition() {
  return transitions[indexOfNextTransition++];
}

bool State::moreTransitionsAvailable() {
  return indexOfNextTransition < transitions.size();
}
