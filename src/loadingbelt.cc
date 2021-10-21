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
  }else if (finished()) {
    throw logic_error{"Read attempt but no symbols left to read from the loading belt."}; 
  }
  if (symbol != '.' && symbol == belt[indexOfHead]) {
    indexOfHead++;
  }
}

bool LoadingBelt::finished() {
  return belt.size() == 0 || belt.size() > 0 && indexOfHead == belt.size();
}