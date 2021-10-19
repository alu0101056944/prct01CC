#include "../include/loadingbelt.h"

#include <iostream>

LoadingBelt::LoadingBelt(string inputWord) : 
    belt(inputWord.begin(), inputWord.end()),
    indexOfHead(0) {}

void LoadingBelt::read(char symbol) {
  if (indexOfHead < belt.size() && symbol != '.' && 
      symbol == belt[indexOfHead]) {
    indexOfHead++;
  }
}

void LoadingBelt::print() {
  cout << indexOfHead;
}