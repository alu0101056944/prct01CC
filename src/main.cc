/**
 * Marcos Barrios
 * Complejidad Computacional
 */

#include <vector>
#include <iostream>

#include "../include/filereader.h"
#include "../include/statefactory.h"
#include "../include/automata.h"

void callValidate(Automata& a) {
  cout << "Type the word to be recognized: " << endl;
  string input = "ab";
  //cin >> input;
  bool isRecognized = a.validate(input);
  cout << "Recognition: " << isRecognized << endl;
}

int main(int, char** argv) {
  FileReader fileReader;
  fileReader.readFile("../bin/APv.txt");
  vector<vector<string>> tr = fileReader.transitions();
  StateFactory stateFactory(fileReader.numberOfStates(),
        fileReader.initialState(), tr);
  Automata a(fileReader.beltAlphabet(), fileReader.stackAlphabet(),
        fileReader.initialStackSymbol());
  callValidate(a);
  /* char choice;
  bool programOn = true;
  while (programOn != false) {
      cout << endl;
      cout << "Stack Automata (empty stack mode)." << endl;
      cout << "Type x to exit." << endl;
      cout << "Type i to input a word." << endl;

      cin >> choice;

      switch (choice) {
        case 'x':
          programOn = false;
          break;
        case 'i':
          callValidate(a);
          break;
        default:
          cout << "Invalid option, please try again. " << endl;
          cin >> choice;
          break;
      }
  } */
}
