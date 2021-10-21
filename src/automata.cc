#include "../include/automata.h"

Automata::Automata(Stack& stack, LoadingBelt& loadingBelt) :
  stack(stack),
  loadingBelt(loadingBelt) {}

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
 */
bool Automata::validate(string inputWord) {
  // to fix stack<int> s;
  
  /**
   * s.push(StateFactory.initialState());
   * while(!stack.empty() && !s.empty()) {
   *  s.top.transitioner().obtainNextTransition()
   * }
   * 
   */
}