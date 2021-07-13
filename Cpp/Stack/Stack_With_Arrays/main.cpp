#include "stack.h"

int main (void) {
  Stack<int> s1 = Stack<int>(5);
  s1.push(20);
  s1.push(12);
  s1.push(-1);

  s1.print();
  return 0;
}
