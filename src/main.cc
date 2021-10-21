/**
 * Marcos Barrios
 * Complejidad Computacional
 */

#include "../include/loadingbelt.h"
#include "../include/State.h"

#include <stack>
using namespace std;
int main() {
  LoadingBelt lb("abc");
  lb.read('.');
  lb.read('a');
  lb.read('b');
  stack<State> s;
}