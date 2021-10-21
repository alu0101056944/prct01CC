#include "../include/stack.h"

#include <algorithm>
#include <stdexcept>

Stack::Stack(char initialSym, string alphabet) :
    initialSym(initialSym),
    alphabet(alphabet) {}

void Stack::push(string symbols) {
  for (int i = 0; i < symbols.size(); i++) {
    if(find(alphabet.begin(), alphabet.end(), symbols[i]) == alphabet.end() ||
        symbols[i] != initialSym) {
      // alphabet doesn't contain symbol[i] or initial symbol
      throw logic_error{"Attempt push of non-alphabet character into stack"};
    }
    stack.push(symbols[i]);
    history.push(symbols[i]);
  }
}

void Stack::pop(char symbol) {
  if (stack.empty()) {
    throw logic_error{"Stack is empty, can't pop() it."};    
  } else if(find(alphabet.begin(), alphabet.end(), symbol) == alphabet.end() ||
      symbol != initialSym) {
    // alphabet doesn't contain symbol or initial symbol
    throw logic_error{"Attempt push of non-alphabet character into stack"};
  } else if (stack.top() != symbol) {
    throw logic_error{"Can't pop(symbol) because symbol isn't on top of the stack"};
  }
  stack.pop();
}

void Stack::fallback() {
  while(!history.empty()) {
    stack.pop();
  }
}

bool Stack::empty() {
  return stack.empty();
}