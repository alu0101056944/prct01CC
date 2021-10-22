#include "../include/loadingbelt.h"

#include <iostream>
#include <algorithm>

LoadingBelt::LoadingBelt(string alphabet) :
    alphabet(alphabet),
    indexOfHead(0) {}

void LoadingBelt::read(char symbol) {
  if(find(alphabet.begin(), alphabet.end(), symbol) == alphabet.end()) {
    // alphabet doesn't contain symbol[i]
    throw logic_error{"Attempt read of non-alphabet character on loading belt"};
  }
  if (symbol != '.' && !isFinished() && symbol == belt[indexOfHead]) {
    indexOfHead++;
    history.push(symbol);
  }
}

void LoadingBelt::fallback() {
  while(!history.empty()) {
    if (history.top() != '.') {
      indexOfHead--;
    }
  }
}

bool LoadingBelt::isFinished() {
  return belt.size() == 0 || belt.size() > 0 && indexOfHead == belt.size();
}

void LoadingBelt::reset(string inputWord) {
  belt = inputWord;
}

void LoadingBelt::clear() {
  belt.clear();
}