/**
 * Marcos Barrios
 * Complejidad Computacional
 * 
 * Used to configure a Stack Automata and a StateFactory object.
 * 
 * Reads a file whose format is the following:
 *  [optionally] # comments
 *  Set of states
 *  Language alphabet of the loading belt
 *  Language alphabet of the stack
 *  Initial state
 *  Set of final states
 *  Transition function (each line is a transition, potentially infinite lines)
 * 
 * A method is defined for each of the components included in the format.
 */
#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

using namespace std;

class FileReader {
  public:
    FileReader();

    /**
     * Obtain the file contents without the comments and extra spaces. Only
     * spaces between words are kept.
     */
    void readFile(string path);

    int numberOfStates();
    string beltAlphabet();
    string stackAlphabet();
    int initialState();
    char initialStackSymbol();
    vector<vector<string>> transitions();
  private:
    vector<string> fileContent;

    // Used on readFile() to remove unnecessary spaces.
    void trim(string& stringToTrim);
};

#endif