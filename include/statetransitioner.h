/**
 * Marcos Barrios
 * Complejidad Computacional ULL
 * 
 * Manages a state stack used for exhaustive transition checking. It is used
 *  in the Automata type to know what transition should be applied next.
 * 
 * Also keeps track of available transitions on each state instance contained in
 *  the state stack.
 * 
 */

#ifndef STATETRANSITIONER_H
#define STATETRANSITIONER_H

#include <vector>
#include <string>
using namespace std;

class StateTransitioner {
  public:
    StateTransitioner();

    StateTransition nextTransition();

};

#endif  