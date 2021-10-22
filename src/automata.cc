#include "../include/automata.h"

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
 */
bool Automata::validate(string inputWord) {
  stack.clear();
  loadingBelt.clear();
  loadingBelt.reset(inputWord);

  stateHistory.push(StateFactory::createState(StateFactory::initialState));
  while(!stack.empty() && !stateHistory.empty()) {
    if (stateHistory.top().moreTransitionsAvailable()) {
      StateTransition transition = stateHistory.top().getNextTransition();
      char stackSymbolToPop = transition.getStackSymbolToPop();
      char beltSymbolToRead = transition.getBeltSymbol();

      if(stack.canPop(stackSymbolToPop) && loadingBelt.canRead(beltSymbolToRead)) {
        loadingBelt.read(beltSymbolToRead);
        stack.pop(stackSymbolToPop);
        stack.push(transition.getStackSymbolsToInsert());
        stateHistory.push(StateFactory::createState(transition.getNextState()));
      }
    } else {
      stack.fallback();
      loadingBelt.fallback();
      stateHistory.pop();
    }
  }
  return loadingBelt.isFinished();
}