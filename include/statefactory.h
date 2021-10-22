/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Stores (state name, transitions) pairs that are used for new State object
 * creation. Meant for the algorithm the Automata uses to search for a path of
 * transitions that recognize the given input word.
 * 
 * Needs to be reset when a new automata is required to calculate the new pairs
 * (state name, transitions).
 * 
 * Here a transition is a string word with the following format:
 *    q1 a A1 q2 [A1 A2 A3 ...]
 *  q1 is current state, a is belt symbol to read, A1 is symbol to
 *  erase from top of the stack, q2 is the next state and A is a symbol
 *  to insert on the stack (might be a set of them separated by spaces).
 * 
 */

#ifndef STATEFACTORY_H
#define STATEFACTORY_H

#include <unordered_map>

#include "./state.h"
#include "./statetransition.h"

class StateFactory {
  public:
    StateFactory(std::string initialState,
        std::vector<std::vector<std::string>>& transitions);

    /**
     * Checks if there is a vector of Transition objects associated to the state
     * name and returns a new State with those transitions.
     * 
     * States keep track of transitions applied, this is used to obtain a new
     * fresh instance of a state whose transitions haven't been applied. It is
     * necessary for Automata state history stack functionality.
     */
    static State createState(std::string stateName);

    /**
     * Reassign the possible transitions - id pairs so that each time a new
     * automata needs to be formed this can be called.
     */
    void resetAutomata(std::string initialState,
        std::vector<std::vector<std::string>>& transitions);

    // Instead of a function a variable will do just fine.
    static std::string initialState;
  private:
    static std::unordered_map<std::string, std::vector<StateTransition>> availableStates;
};

#endif
