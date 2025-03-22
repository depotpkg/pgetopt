#include <stdio.h>

#include "pgetopt.h"

static char* short_options = "i:o:vh";

static struct option long_options[] = {
    {
        .name = "input",
        .has_arg = required_argument,
        .flag = NULL,
        .val = 'i',
    },
    {
      .name = "output",
      .has_arg = required_argument,
      .flag = NULL,
      .val = 'o',
  },
    {
        .name = "version",
        .has_arg = no_argument,
        .flag = NULL,
        .val = 'v',
    },
    {
        .name = "help",
        .has_arg = no_argument,
        .flag = NULL,
        .val = 'h',
    },
    {NULL, 0, NULL, 0},
};

int main(int argc, char* argv[]) {
  int opt;
  int opt_index;
  while ((opt = getopt_long(argc, argv, short_options, long_options, &opt_index)) != -1) {
    switch (opt) {
    case 'i':
      printf("input: %s\n", optarg);
      break;
    case 'o':
      printf("output: %s\n", optarg);
      break;
    case 'v':
      printf("v0.0.1\n");
      break;
    case 'h':
      printf("help!\n");
      break;
    default:
      printf("program stopped\n");
      return 1;
    }
  }
  return 0;
}
