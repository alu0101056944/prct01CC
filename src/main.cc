/**
 * Marcos Barrios
 * Complejidad Computacional
 */

#include "../include/filereader.h"

#include <iostream>
#include <stack>
using namespace std;
int main() {
  FileReader fileReader;
  fileReader.readFile("../bin/APv.txt");
  cout << fileReader.numberOfStates() << endl;
  cout << fileReader.initialStackSymbol() << endl;
  cout << fileReader.stackAlphabet() << endl << endl;
  cout << fileReader.beltAlphabet() << endl << endl;
  cout << fileReader.initialState() << endl;  
}