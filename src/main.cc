/**
 * Marcos Barrios
 * Complejidad Computacional
 */

#include <vector>

#include "../include/filereader.h"
#include "../include/statefactory.h"

int main() {
  FileReader fileReader;
  fileReader.readFile("../bin/APv.txt");
  vector<vector<string>> ref = fileReader.transitions();
  StateFactory stateFactory(fileReader.numberOfStates(), fileReader.initialState(), ref);
  State a = stateFactory.createState(2);
  a.print();
}