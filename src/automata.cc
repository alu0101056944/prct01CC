#include "../include/automata.h"

#include <iostream>
#include "../include/statetransition.h"
#include "../include/statefactory.h"
#include "../include/state.h"

#include <stack>
using namespace std;

Automata::Automata(string beltAlphabet, string stackAlphabet,
    char initialStackSym) :
    beltAlphabet(beltAlphabet),
    stackAlphabet(stackAlphabet),
    initialStackSym(initialStackSym),
    stack(initialStackSym, stackAlphabet),
    loadingBelt(beltAlphabet) {}

/**
 * Use a state stack to keep track of states, each of which has a list
 * of transitions and know which transitions have been applied to it.
 * 
 * After each transition depending on if the state is the same or not I
 * create a new fresh state instance or I copy an existing state, which
 * will have the same transitions available than the previous state stack
 * top.
 */
bool Automata::validate(string inputWord) {
  stack.clear();
  loadingBelt.clear();
  loadingBelt.reset(inputWord);
  stateHistory.push(StateFactory::createState(StateFactory::initialState));
  while(!stack.empty()) {
    if (stateHistory.top().moreTransitionsAvailable()) {
      StateTransition transition = stateHistory.top().getNextTransition();
      loadingBelt.read(transition.getBeltSymbol());
      stack.push(transition.getStackSymbolsToInsert());
      stack.pop(transition.getStackSymbolToPop());
      cout << "transition: " << transition.getBeltSymbol() << ", " << transition.getStackSymbolToPop() << ", " << transition.getStackSymbolsToInsert() << endl;
      int nextState = transition.getNextState();
      cout << "nextState: " << nextState << endl;
      if (stateHistory.top().isSameState(nextState)) {
        cout << "existing state " << endl;
        stateHistory.push(stateHistory.top().copy());
      } else {
        cout << "fresh state " << endl;
        stateHistory.push(StateFactory::createState(transition.getNextState()));
      }
      cout << endl;
    } else {
      cout << "fallback" << endl;
      stack.fallback();
      loadingBelt.fallback();
      stateHistory.pop();
    }
  }
  return loadingBelt.isFinished();
}