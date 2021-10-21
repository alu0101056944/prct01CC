/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Creates a new instance of a given state, which contains associated
 *  state transitions.
 * 
 * Used by the StateTransitioner when a new transition is applied to get a new
 *  instance of the same state.
 */

#ifndef STATEFACTORY_H
#define STATEFACTORY_H

#include <unordered_map>

#include "./state.h"
#include "./statetransition.h"

using namespace std;

class StateFactory {
  public:
    StateFactory(int numberOfStates, vector<vector<string>>& transitions);

    /**
     * Obtain a new state instance from any state used in the current automata.
     */
    static State createState(int id);

    /**
     * Reassign the possible transitions - id pairs so that each time a new
     * automata needs to be formed this can be called.
     */
    void resetAutomata(int numberOfStates, vector<vector<string>>& transitions);
  private:
    static unordered_map<int, vector<StateTransition>> availableStates;
};

#endif
