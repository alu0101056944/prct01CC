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


class StateFactory {
  public:
    StateFactory(int numberOfStates, int initialState,
        std::vector<std::vector<std::string>>& transitions);

    /**
     * Obtain a new state instance from any state used in the current automata.
     */
    static State createState(int id);

    /**
     * Reassign the possible transitions - id pairs so that each time a new
     * automata needs to be formed this can be called.
     */
    void resetAutomata(int numberOfStates, int initialState,
        std::vector<std::vector<std::string>>& transitions);

    static int initialState;
  private:
    static std::unordered_map<int, std::vector<StateTransition>> availableStates;
};

#endif
