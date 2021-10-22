/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * States of the automata. Since it is an empty stack automata there won't be any
 *  final states.
 * It contains a set of transitions and each can be established as available or
 *  not available for exploration.
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
    State(int id, std::vector<StateTransition> transitions);
    
    StateTransition getNextTransition();
    bool moreTransitionsAvailable();
    bool isSameState(int idOfOtherState);
  private:
    int id;
    int indexOfNextTransition;
    std::vector<StateTransition> transitions;
};

#endif
