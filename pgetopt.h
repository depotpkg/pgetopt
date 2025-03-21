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

POPT_API int pgetopt();

#endif  // PGETOPT_H_
