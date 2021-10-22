#include "../include/loadingbelt.h"

#include <iostream>
#include <algorithm>

LoadingBelt::LoadingBelt(string alphabet, string inputWord) : 
    belt(inputWord.begin(), inputWord.end()),
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
