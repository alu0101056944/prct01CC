#include "../include/automata.h"

#include "../include/statetransition.h"
#include "../include/statefactory.h"
#include "../include/state.h"

#include <stack>
using namespace std;

Automata::Automata(string beltAlphabet, string stackAlphabet,
    char initialStackSym, string inputWord) :
    beltAlphabet(beltAlphabet),
    stackAlphabet(stackAlphabet),
    initialStackSym(initialStackSym),
    stack(initialStackSym, stackAlphabet),
    loadingBelt(beltAlphabet, inputWord) {}

/**
 * Solo paro de ejecutar cuando la pila este vacia. Si la palabra es valida
 * entonces la pila se vaciara en el momento adecuado. Igual que si no es
 * valida entonces parara cuando no hayan transiciones pendientes por iterar,
 * en cuyo caso se considera que la palabra no es valida.
 * 
 * Puedo utilizar un objeto para controlar las transiciones de estados, que se
 * encargue de devolver cuando un estado sigue teniendo transiciones disponibles.
 * El problema esta en saber las transiciones disponibles. Quizas puede contener
 * un array de forma que sepa que transiciones han sido aplicadas. La ventaja es
 * que puedo mantener la clase estado tal como estaba, una simple clase contenedora
 * de informacion sobre estado y transiciones asignadas.
 * 
 * All transitions  of the states are applied instead of filtering them previosly but
 * the belt and stack won't change unless proper symbols are given.
 */
bool Automata::validate(string inputWord) {
  stateHistory.push(StateFactory::createState(StateFactory::initialState));
  while(!stack.empty()) {
    if (stateHistory.top().moreTransitionsAvailable()) {
      StateTransition transition = stateHistory.top().getNextTransition();
      loadingBelt.read(transition.getBeltSymbol());
      stack.push(transition.getStackSymbolsToInsert());
      stateHistory.push(StateFactory::createState(transition.getNextState()));
    } else {
      stack.fallback();
      loadingBelt.fallback();
      stateHistory.pop();
    }
  }
  return loadingBelt.isFinished();
}