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
    LoadingBelt(string inputWord);

    /**
     * Moves the head if symbol is equal to the current cell's element the
     *  header is pointing to.
     * If symbol is empty char then head stays in position.
     */
    void read(char symbol);
    void print();
  private:
    vector<char> belt;
    int indexOfHead;
};
#endif