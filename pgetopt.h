#ifndef PGETOPT_H_
#define PGETOPT_H_

#include <stddef.h>

#if !defined(POPT_API)
#if defined(POPT_DLL)
#if defined(_MSC_VER)
#if POPT_IMPLEMENTATION
#define POPT_API __declspec(dllexport)
#else
#define POPT_API __declspec(dllimport)
#endif  // POPT_IMPLEMENTATION
#else
#define POPT_API __attribute__((visibility("default")))
#endif  // defined(_MSC_VER)
#else
#define POPT_API
#endif  // defined(POPT_DLL)
#endif  // !defined(POPT_API)

/*
 * GNU-like getopt_long()
 */
#define no_argument 0
#define required_argument 1
#define optional_argument 2

struct option {
  /* name of long option */
  const char* name;
  /*
   * one of no_argument, required_argument, and optional_argument:
   * whether option takes an argument
   */
  int has_arg;
  /* if not NULL, set *flag to val when option found */
  int* flag;
  /* if flag not NULL, value to set *flag to; else return value */
  int val;
};

/* getopt(3) external variables */
extern int opterr;   /* if error message should be printed */
extern int optind;   /* index into parent argv vector */
extern int optopt;   /* character checked for validity */
extern int optreset; /* reset getopt */
extern char* optarg; /* argument associated with option */

POPT_API int getopt(int nargc, char* const* nargv, const char* options);

POPT_API int getopt_long(int nargc,
                         char* const* nargv,
                         const char* options,
                         const struct option* long_options,
                         int* idx);

POPT_API int getopt_long_only(int nargc,
                              char* const* nargv,
                              const char* options,
                              const struct option* long_options,
                              int* idx);

#endif  // PGETOPT_H_
