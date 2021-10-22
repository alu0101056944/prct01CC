#include "../include/loadingbelt.h"

#include <iostream>
#include <algorithm>

LoadingBelt::LoadingBelt(std::string alphabet) :
    alphabet(alphabet),
    indexOfHead(0) {}

void LoadingBelt::read(char symbol) {
  if(find(alphabet.begin(), alphabet.end(), symbol) == alphabet.end()) {
    // alphabet doesn't contain symbol[i]
    throw std::logic_error{"Attempt read of non-alphabet character on loading belt"};
  }
  if (symbol != '.' && symbol == belt[indexOfHead]) {
    indexOfHead++;
  }
  history.push(symbol);
}

void LoadingBelt::fallback() {
  if (!history.empty() && history.top() != '.') {
    indexOfHead--;
  }
  history.pop();
}

bool LoadingBelt::canRead(char symbol) {
  return !isFinished() && belt[indexOfHead] == symbol || belt[indexOfHead] == '.';
}

bool LoadingBelt::isFinished() {
  return belt.size() == 0 || belt.size() > 0 && indexOfHead == belt.size();
}

void LoadingBelt::reset(std::string inputWord) {
  belt.clear();
  indexOfHead = 0;
  belt.append(inputWord);
}
