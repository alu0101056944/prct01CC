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
  StateFactory stateFactory(fileReader.numberOfStates(), vector<vector<string>>());
}