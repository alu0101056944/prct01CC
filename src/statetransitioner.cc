#include "../include/statetransitioner.h"

#include "../include/statefactory.h"

StateTransitioner::StateTransitioner() {
  stateHistory.push(StateFactory::createState(StateFactory::initialState));
}

StateTransition StateTransitioner::nextTransition() {
  if (stateHistory.top().nonAppliedTransitions()) {
    return stateHistory.top().getNextTransition();
  }
}