/**
 * Marcos Barrios
 * Complejidad Computacional
 * 
 * Automata por vaciado de pila.
 * 
 * This is the main file where the terminal inputs are processed. It needs to be given
 * a file path as first argument.
 */

#include <vector>
#include <iostream>

#include "../include/filereader.h"
#include "../include/statefactory.h"
#include "../include/automata.h"

void callValidate(FileReader& fileReader) {
  using namespace std;
  Automata a(fileReader.beltAlphabet(), fileReader.stackAlphabet(),
        fileReader.initialStackSymbol());
  cout << "Type the word to be recognized: " << endl;
  string input = "";
  cin >> input;
  cout << (a.validate(input) ? "Recognized" : "Not recognized");
  cout << endl;
}

int main(int, char** argv) {
  using namespace std;
  FileReader fileReader;
  fileReader.readFile("../bin/APv.txt");
  std::vector<vector<std::string>> tr = fileReader.transitions();
  StateFactory stateFactory(fileReader.numberOfStates(),
        fileReader.initialState(), tr);
  callValidate(fileReader);
  
  char choice;
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
          callValidate(fileReader); // validar cadena
          break;
        default:
          cout << "Invalid option, please try again. " << endl;
          cin >> choice;
          break;
      }
  }
}
