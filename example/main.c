#include "pgetopt.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
  int output = pgetopt();
  printf("pgetopt output: %d\n", output);
  return 0;
}
