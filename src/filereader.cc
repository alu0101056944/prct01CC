#include "../include/filereader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>

FileReader::FileReader() {}

/**
 * Get line, count until # is found, then substring the part until that
 *  character. Trim the result to get only the useful words with spaces
 *  only in between them.
 */
void FileReader::readFile(string path) {
  ifstream inFile(path);
  string line;
  while (getline(inFile, line)) {
      int amountOfUsefulCharacters = 0;
      for (int i = 0; i < line.size(); i++) {
        if (line[i] != '#') {
          amountOfUsefulCharacters++;
        } else {
          break;
        }
      }
      string usefulString = line.substr(0, amountOfUsefulCharacters);
      trim(usefulString);
      if (usefulString.size() > 0) {
        fileContent.push_back(usefulString);
      }
  }
}

/**
 * (Private function)
 * Trims the given string starting from the right.
 * 
 * Use a lambda to check each character from the right that are not space, the
 *  ones that are get removed from the string.
 */
void FileReader::trim(string& stringToTrim) {
    stringToTrim.erase(find_if(stringToTrim.rbegin(), stringToTrim.rend(), 
        [](unsigned char ch) {
          return !std::isspace(ch);
        }
      ).base(), stringToTrim.end());
}

/**
 * Get the amount of words in the string with the state names.
 * Asssumes first line of fileContent vector contains the state names.
 */
int FileReader::numberOfStates() {
  vector<string> words;
  stringstream ss(fileContent[0]);
  string word;
  while(getline(ss, word, ' ')) {
    words.push_back(word);
  }
  return words.size();
}

/**
 * Assume second line of fileContent is the belt alphabet.
 */
string FileReader::beltAlphabet() {
  string alphabet = "";
  stringstream ss(fileContent[1]);
  string word;
  while(getline(ss, word, ' ')) {
    alphabet.append(word);
  }
  return alphabet;
}

/**
 * Assume third line of fileContent is the stack alphabet.
 */
string FileReader::stackAlphabet() {
  string alphabet = "";
  stringstream ss(fileContent[2]);
  string word;
  while(getline(ss, word, ' ')) {
    alphabet.append(word);
  }
  return alphabet;
}

/**
 * Assume second character of the line corresponding to the initial state
 * is the number of the initial state. Ex: 'q3' where 3 is the number of
 * the initial state.
 */
int FileReader::initialState() {
  return stoi(fileContent[3].erase(0, 1)); // remove the q and keep the number
}

/**
 * Assume fifth fileContent's vector element is the initial stack symbol
 */ 
char FileReader::initialStackSymbol() {
  char output[1];
  strcpy(output, fileContent[4].c_str());
  return output[0];
}

/**
 * Any number of transitions is stored in a vector, where each element is at
 *  the same time another vector whose elements are the values of the transition.
 */
vector<vector<string>> FileReader::transitions() {
  vector<vector<string>> transitions;
  for (int i = 6; i < fileContent.size(); i++) { // There's always 6 lines at least
    vector<string> transition;
    stringstream ss(fileContent[i]);
    string word;
    while(getline(ss, word, ' ')) {
      transition.push_back(word);
    }
    transitions.push_back(transition);
  }
  return transitions;
}
