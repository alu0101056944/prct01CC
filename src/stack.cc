#include "../include/stack.h"

#include <algorithm>
#include <stdexcept>

Stack::Stack(char initialSym, string alphabet) :
    initialSym(initialSym),
    alphabet(alphabet) {}

void Stack::push(string symbols) {
  for (int i = symbols.size() - 1; i >= 0; i--) {
    if(find(alphabet.begin(), alphabet.end(), symbols[i]) == alphabet.end() &&
        symbols[i] != initialSym && symbols[i] != '.') {
      // alphabet doesn't contain symbol[i] or initial symbol
      throw logic_error{"Attempt push of non-alphabet character into stack"};
    }
    if (symbols[i] != '.') {
      stack.push(symbols[i]);
    }
    history.push(symbols[i]);
  }
}

void Stack::pop(char symbol) {
  if (stack.empty()) {
    throw logic_error{"Stack is empty, can't pop() it."};    
  } else if(find(alphabet.begin(), alphabet.end(), symbol) == alphabet.end() &&
      symbol != initialSym) {
    // alphabet doesn't contain symbol or initial symbol
    throw logic_error{"Attempt push of non-alphabet character into stack"};
  }
  if (stack.top() == symbol) {
    stack.pop();
  }
}

void Stack::clear() {
  for (int i = 0; i < stack.size(); i++) {
    stack.pop();
  }
  stack.push(initialSym);
}

void Stack::fallback() {
  history.pop();
}

bool Stack::canPop(char symbol) {
  return stack.top() == symbol && !stack.empty();
}

bool Stack::empty() {
  return stack.empty();
}
