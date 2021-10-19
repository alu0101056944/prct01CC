/**
 * Marcos Barrios
 * Complejidad Computacional
 */

#include "../include/loadingbelt.h"

int main() {
  LoadingBelt lb("abc");
  lb.read('.');
  lb.print();
  lb.read('a');
  lb.read('b');
  lb.print();
}