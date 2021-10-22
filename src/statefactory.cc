#include "../include/statefactory.h"

#include <sstream>
#include <string>


StateFactory::StateFactory(std::string initialState,
    std::vector<std::vector<std::string>>& transitions) {
  resetAutomata(initialState, transitions);
}

// declarations of static members
std::unordered_map<std::string, std::vector<StateTransition>> StateFactory::availableStates;

std::string StateFactory::initialState = ""; // temporal value

/**
 * Parse the format into StateTransition objects and assign them to the
 *  corresponding available state's transitions vector depending on the
 *  current state's name. Ex: (p a S A) sets p as available state if it wasn't
 *  added before and creates a new vector with a single transition
 */
void StateFactory::resetAutomata(std::string initialState,
     std::vector<std::vector<std::string>>& transitions) {
  availableStates.clear();
  StateFactory::initialState = initialState;
  for(int i = 0; i < transitions.size(); i++) {
    std::string stackSymbolsToInsert = "";
    for(int j = 4; j < transitions[i].size(); j++) {
      stackSymbolsToInsert.append(transitions[i][j]);
    }
    StateTransition stateTransition(
        transitions[i][1][0], // beltSymbol
        transitions[i][2][0], // stackSymbolToPop
        stackSymbolsToInsert,
        transitions[i][3] // nextState
      );
    std::string currentState = transitions[i][0];
    if (availableStates.find(currentState) != availableStates.end()) {
      availableStates[currentState].push_back(stateTransition); // add new transition to the state
    } else {
      std::vector<StateTransition> stateTransitions;
      stateTransitions.push_back(stateTransition);
      availableStates.insert({currentState, stateTransitions});
    }
  }
}

State StateFactory::createState(std::string stateName) {
  return State(stateName, availableStates[stateName]);
}
