#include "../include/state.h"

State::State(int id, vector<StateTransition> transitions) : 
    id(id), transitions(transitions) {}
