#include "../include/loadingbelt.h"

#include <iostream>
#include <algorithm>

LoadingBelt::LoadingBelt(vector<char> alphabet, string inputWord) : 
    belt(inputWord.begin(), inputWord.end()),
    alphabet(alphabet),
    indexOfHead(0) {}

void LoadingBelt::read(char symbol) {
  if(find(alphabet.begin(), alphabet.end(), symbol) == alphabet.end()) {
    // alphabet doesn't contain symbol[i]
    throw logic_error{"Attempt read of non-alphabet character from loading belt"};
  }
  if (indexOfHead < belt.size() && symbol != '.' && 
      symbol == belt[indexOfHead]) {
    indexOfHead++;
  }
}

bool LoadingBelt::finished() {
  return belt.size() == 0 || belt.size() > 0 && indexOfHead == belt.size();
}