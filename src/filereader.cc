#include "../include/filereader.h"

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
void FileReader::readFile(std::string path) {
  std::ifstream inFile(path);
  std::string line;
  while (getline(inFile, line)) {
      int amountOfUsefulCharacters = 0;
      for (int i = 0; i < line.size(); i++) {
        if (line[i] != '#') {
          amountOfUsefulCharacters++;
        } else {
          break;
        }
      }
      std::string usefulString = line.substr(0, amountOfUsefulCharacters);
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
void FileReader::trim(std::string& stringToTrim) {
    stringToTrim.erase(std::find_if(stringToTrim.rbegin(), stringToTrim.rend(), 
        [](unsigned char ch) {
          return !std::isspace(ch);
        }
      ).base(), stringToTrim.end());
}

/**
 * Assume second line of fileContent is the belt alphabet.
 */
std::string FileReader::beltAlphabet() {
  std::string alphabet = "";
  std::stringstream ss(fileContent[1]);
  std::string word;
  while(getline(ss, word, ' ')) {
    alphabet.append(word);
  }
  return alphabet;
}

/**
 * Assume third line of fileContent is the stack alphabet.
 */
std::string FileReader::stackAlphabet() {
  std::string alphabet = "";
  std::stringstream ss(fileContent[2]);
  std::string word;
  while(getline(ss, word, ' ')) {
    alphabet.append(word);
  }
  return alphabet;
}

/**
 * The 4th line will always be the initial state's name. The line won't have
 * any comments or extra spaces since file content has already been processed
 * when read.
 */
std::string FileReader::initialState() {
  return fileContent[3];
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
 * Assume 6th line is the first transition, so iterate fileContent's lines from
 * there and split each line into words, then save it into a vector of vectors.
 */
std::vector<std::vector<std::string>> FileReader::transitions() {
  using namespace std;
  vector<vector<string>> transitions;

  for (int i = 5; i < fileContent.size(); i++) { // There's always 6 lines at least
    vector<string> transition;

    stringstream ss(fileContent[i]); // used to split into words
    string word;
    while(getline(ss, word, ' ')) {
      transition.push_back(word);
    }

    transitions.push_back(transition);
  }
  return transitions;
}
