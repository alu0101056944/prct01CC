#include "../include/automata.h"

#include "../include/statetransition.h"
#include "../include/statefactory.h"
#include "../include/state.h"

#include <stack>

Automata::Automata(std::string beltAlphabet, std::string stackAlphabet,
    char initialStackSym) :
    beltAlphabet(beltAlphabet),
    stackAlphabet(stackAlphabet),
    initialStackSym(initialStackSym),
    stack(initialStackSym, stackAlphabet),
    loadingBelt(beltAlphabet) {}

/**
 * A state history is kept to fallback to a previous state when there aren't
 * transitions available to apply. After stack and lb clearing to allow this
 * function to be called multiple times, initial state is pushed. Then it
 * attempts every possible transition path while stack isn't emptyied or there
 * aren't more transitions to be applied.
 * 
 * Each state keeps track of the transitions it has been applied. Each transition
 * leads to a new State on top of the stack. States without available transitions
 * are removed from the top of the stack to explore other transition paths.
 */
bool Automata::validate(std::string inputWord) {
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