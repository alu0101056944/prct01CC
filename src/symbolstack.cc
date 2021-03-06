#include "../include/symbolstack.h"

#include <algorithm>
#include <stdexcept>

SymbolStack::SymbolStack(char initialSym, std::string alphabet) :
    initialSym(initialSym),
    alphabet(alphabet) {}

/**
 * Push first last char of the symbols string.
 */
void SymbolStack::push(std::string symbols) {
  for (int i = symbols.size() - 1; i >= 0; i--) {
    if(find(alphabet.begin(), alphabet.end(), symbols[i]) == alphabet.end() &&
        symbols[i] != initialSym && symbols[i] != '.') {
      // alphabet doesn't contain symbol[i] or initial symbol
      throw std::logic_error{"Attempt push of non-alphabet character into stack"};
    }
    if (symbols[i] != '.') {
      stack.push(symbols[i]);
    }
    history.push(symbols[i]);
  }
}

void SymbolStack::pop(char symbol) {
  if (stack.empty()) {
    throw std::logic_error{"Stack is empty, can't pop() it."};    
  } else if(find(alphabet.begin(), alphabet.end(), symbol) == alphabet.end() &&
      symbol != initialSym) {
    // alphabet doesn't contain symbol or initial symbol
    throw std::logic_error{"Attempt push of non-alphabet character into stack"};
  }
  if (stack.top() == symbol) {
    stack.pop();
  }
}

void SymbolStack::reset() {
  stack = std::stack<char>(); // to avoid typing a loop
  stack.push(initialSym);
}

void SymbolStack::fallback() {
  history.pop();
}

bool SymbolStack::canPop(char symbol) {
  return stack.top() == symbol && !stack.empty();
}

bool SymbolStack::empty() {
  return stack.empty();
}
