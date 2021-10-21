/**
 * Marcos Barrios
 * Complejidad Computacional
 * 
 * Utilized by the automata to store the input word, each letter on a different
 *  cell.
 * 
 * Each time a transition is applied the header that points to the current cell
 *  moves to point to the next cell.
 * 
 * An empty symbol can be read, which means not to apply header movement on one
 *  transition.
 * 
 * TODO: Implement language alphabet checks.
 */
#ifndef LOADINGBELT_H
#define LOADINGBELT_H

#include <vector>
#include <string>

using namespace std;

class LoadingBelt {
  public:
    LoadingBelt(vector<char> alphabet, string inputWord);

    /**
     * Moves the head if symbol is equal to the current cell's element the
     *  header is pointing to.
     * If symbol is empty char then head stays in position.
     */
    void read(char symbol);

    /**
     * If an input word was given and head points at the following cell to the last
     * cell containing the last character of the input word. Also if an input word
     * wasn't given (belt is empty).
     */
    bool finished();
  private:
    vector<char> belt;
    vector<char> alphabet;
    int indexOfHead;
};
#endif