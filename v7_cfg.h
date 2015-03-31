

#ifndef V7_CFG_INCLUDED
#define V7_CFG_INCLUDED

/** cond comp section **/

#define V7_EXE
/* #define V7_UNIT_TEST */
#define V7_EXPOSE_PRIVATE

/* #define __GNUC__ */

#if (defined(_WIN32) && !defined(__MINGW32__) && !defined(__MINGW64__)) || \
    (defined(_MSC_VER) && _MSC_VER <= 1200)
#define V7_WINDOWS
#endif

/* #define V7_DISABLE_REGEX */
/* #define HAS_V7_INFINITY */
/* #define HAS_V7_NAN */
/* #define V7_BROKEN_NAN */

/** macros section **/

#define V7_MALLOC malloc
#define V7_CALLOC calloc
#define V7_REALLOC realloc
#define v7_FREE free

#define SLRE_MALLOC V7_MALLOC
#define SLRE_FREE v7_FREE

/** typedef section **/

typedef __int64 sint64_t;
typedef unsigned __int64 uint64_t;
typedef int int32_t;
typedef int sint32_t;
typedef unsigned int uint32_t;
typedef short sint16_t;
typedef unsigned short uint16_t;
typedef signed char sint8_t;
typedef unsigned char uint8_t;
// typedef unsigned long  size_t;

/*********************/

#ifdef V7_WINDOWS
typedef unsigned __int64 uint64_t;
#define vsnprintf _vsnprintf
#define snprintf _snprintf
#define isnan(x) _isnan(x)
#define isinf(x) (!_finite(x))
#define __unused
typedef __int64 int64_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef unsigned long uintptr_t;
#define __func__ ""

/* Visual studio 2012+ has signbit() */
#if _MSC_VER < 1700
static int signbit(double x) {
  double s = _copysign(1, x);
  return s < 0;
}
#endif
#else
#include <inttypes.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#endif

/* Visual studio 2012+ has round() */
#if (defined(V7_WINDOWS) && _MSC_VER < 1700) || defined(__WATCOM__)
static double round(double n) { return n; }
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* V7_CFG_INCLUDED */
