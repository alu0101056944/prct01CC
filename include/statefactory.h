/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Creates a new instance of a given state, which contains associated
 *  state transitions.
 * 
 * Used by the automata when a new transition is applied.
 */

#ifndef STATEFACTORY_H
#define STATEFACTORY_H

#include "./state.h"

class StateFactory {
  public:
    StateFactory();

    State createState(int id);
};

#endif
