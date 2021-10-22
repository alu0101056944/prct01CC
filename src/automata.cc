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
 */
bool Automata::validate(string inputWord) {
  stack.clear();
  loadingBelt.clear();
  loadingBelt.reset(inputWord);

  stateHistory.push(StateFactory::createState(StateFactory::initialState));
  while(!stack.empty() && !stateHistory.empty()) {
    if (!stack.empty()) cout << "non enmpty stack" << endl;
    if (!stateHistory.empty()) cout << "non empty state history" << endl;
    if (stateHistory.top().moreTransitionsAvailable()) {
      StateTransition transition = stateHistory.top().getNextTransition();
      char stackSymbolToPop = transition.getStackSymbolToPop();
      char beltSymbolToRead = transition.getBeltSymbol();
      cout << "Checking transition: " << beltSymbolToRead << ", " << stackSymbolToPop << ", " << transition.getStackSymbolsToInsert() << endl;

      if(!stack.canPop(stackSymbolToPop)) cout << "can't pop" << endl;
      if(!loadingBelt.canRead(beltSymbolToRead)) cout << "can't read" << endl;
      if(stack.canPop(stackSymbolToPop) && loadingBelt.canRead(beltSymbolToRead)) {
        loadingBelt.read(beltSymbolToRead);
        stack.pop(stackSymbolToPop);
        stack.push(transition.getStackSymbolsToInsert());
        cout << "applied transition: " << beltSymbolToRead << ", " << stackSymbolToPop << ", " << transition.getStackSymbolsToInsert() << endl;
        stateHistory.push(StateFactory::createState(transition.getNextState()));
        cout << "new state: " << transition.getNextState() << endl << endl;
      }
    } else {
      stack.fallback();
      loadingBelt.fallback();
      stateHistory.pop();
    }
    cout << "next itr" << endl;
  }
  return loadingBelt.isFinished();
}