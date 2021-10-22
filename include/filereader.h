/**
 * Marcos Barrios
 * Complejidad Computacional
 * 
 * Reads a formatted file and returns different components of the file on each
 *  function.
 * 
 * Used to configure a StateFactory object which allows the Automata to obtain
 * new instances of available states. Those instances are inserted on a state
 * history, which is used to test transition paths.
 * 
 * Reads a file whose format is the following:
 *  [optionally] # comments
 *  Set of states
 *  Language alphabet of the loading belt
 *  Language alphabet of the stack
 *  Initial state
 *  Initial symbol of the stack
 *  Transition function (each line is a transition, potentially infinite lines)
 * 
 *  A method is defined for each of the components defined in the format.
 */
#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

class FileReader {
  public:
    FileReader();

    /**
     * Obtain the file contents leaving out the comments and extra spaces. Only
     * spaces between words are kept.
     * 
     * Should be called each time a new Automata needs to be constructed. Other
     * functions of this class return values depending on the file content's set
     * by this function.
     */
    void readFile(std::string path);

    /**
     * Used by Automata to instantiate loading belt and allow it to check for
     * alphabet. It won't read a symbol that it's not on it's alphabet.
     */
    std::string beltAlphabet();

    /**
     * Used by Automata to instantiate stack and allow it to check for alphabet.
     * A stack won't operate with symbols that are not from it's alphabet. Only
     * exception is '.' char which means no symbol.
     */
    std::string stackAlphabet();

    /**
     * StateFactory uses this to get the name of the initial state.
     */
    std::string initialState();

    /**
     * StateFactory uses this. Stack needs to have a symbol from creation by
     *  definition.
     */
    char initialStackSymbol();

    /**
     * Meant to be used by StateFactory to store the possible transitions. Each
     * transition will be associated with a state name, which will later be used
     * to create new fresh instances of a given state in the automata.
     */
    std::vector<std::vector<std::string>> transitions();
  private:
    std::vector<std::string> fileContent;

    // Used on readFile() to remove unnecessary spaces.
    void trim(std::string& stringToTrim);
};

#endif