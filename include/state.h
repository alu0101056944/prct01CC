/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Contains transitions and an index that points to the next transition that will
 * be returned if requested. It is used by the Automata to keep track of the
 * transitions that can be applied. Once all transitions have been returned the
 * State is removed from the state history stack and rendered useless.
 * 
 * There are no final states because this implementation is an Emptyer Stack
 * Automata. (Automata por vaciado de pila)
 * 
 * States are stacked during execution time as transitions are applied by the automata.
 *  Current state being executed is the one on top of the stack. As transitions are
 *  applied they become unavailable. When a state has no possible transitions left, it
 *  is removed from the stack of states, ready to be deleted from the memory.
 */

#ifndef STATE_h
#define STATE_h

#include <vector>

#include "./statetransition.h"

class State {
  public:
    State(std::string stateName, std::vector<StateTransition> transitions);
    
    /**
     * Return the next transition that hasn't been applied.
     * Used by Automata.
     */
    StateTransition getNextTransition();

    /**
     * To avoid getting null transition objects, this function is called
     * before getNextTransition()
     */
    bool moreTransitionsAvailable();
  private:
    std::string stateName;
    int indexOfNextTransition;
    std::vector<StateTransition> transitions;
};

#endif
