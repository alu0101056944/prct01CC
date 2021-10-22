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
 */
#ifndef LOADINGBELT_H
#define LOADINGBELT_H

#include <vector>
#include <stack>
#include <string>

class LoadingBelt {
  public:
    LoadingBelt(std::string alphabet);

    /**
     * Moves the head if symbol is equal to the current cell's element the
     *  header is pointing to.
     * If symbol is empty char then head stays in position.
     */
    void read(char symbol);

    /**
     * Used when I need to go back to a previous state. Moves the head to the
     * position it was originally since the last state change. Clears the history
     * aswell.
     */
    void fallback();

    /**
     * Used to know if a word was successfully read.
     * 
     * Finished if an input word was given and head points beyond the last cell
     * containing the last character of the input word. Also if an input word
     * wasn't given (belt is empty).
     */
    bool isFinished();

    /**
     * Clears the loading belt and fills it back with a new inputWord.
     */
    void reset(std::string inputWord);

    /**
     * Automata needs to know if a transition can be applied or not. This function
     * does exactly that; checks if symbol can be read.
     */
    bool canRead(char symbol);

  private:
    std::string belt;
    std::string alphabet;
    int indexOfHead;
    std::stack<char> history;
};
#endif