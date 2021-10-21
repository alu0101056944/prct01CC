#include "../include/statefactory.h"

#include <sstream>
#include <string>


StateFactory::StateFactory(int numberOfStates, int initialState,
    vector<vector<string>>& transitions) {
  resetAutomata(numberOfStates, initialState, transitions);
}

unordered_map<int, vector<StateTransition>> StateFactory::availableStates;

int StateFactory::initialState = 0;

/**
 * Here a transition is a string word with the following format:
 *    q1 a A1 q2 A[ A2, A3, ...]
 *  q1 is current state, a is belt symbol to read, A1 is symbol to
 *  erase from top of the stack, q2 is the next state and A is a symbol
 *  to insert on the stack (might be a set of them separated by spaces).
 * 
 * I parse the format into StateTransition objects and assign them to the
 *  corresponding available state's transitions vector.
 */
void StateFactory::resetAutomata(int numberOfStates, int initialState,
     vector<vector<string>>& transitions) {
  availableStates.clear();
  for (int i = 0; i < numberOfStates; i++) { //initialize possible states
    availableStates.insert({i, vector<StateTransition>()});
  }
  StateFactory::initialState = initialState;

  for(int i = 0; i < transitions.size(); i++) {
    char beltSymbol = transitions[i][1][0]; // only has one character
    char stackSymbolToPop = transitions[i][2][0]; // only has one character
    string stackSymbolsToInsert = "";
    for(int j = 4; j < transitions[i].size(); j++) { // append all the symbols to be inserted
      stackSymbolsToInsert.append(transitions[i][j]);
    }
    int nextState = stoi(transitions[i][3].erase(0, 1)); // remove q char. and keep the number
    StateTransition stateTransition(beltSymbol, stackSymbolToPop, stackSymbolsToInsert,
        nextState);
    
    int currentState = stoi(transitions[i][0].erase(0, 1));
    availableStates[currentState].push_back(stateTransition); // add new transition to the state
  }
}

State StateFactory::createState(int id) {
  return State(id, availableStates[id]);
}
