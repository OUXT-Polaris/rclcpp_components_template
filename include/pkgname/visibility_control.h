#ifndef PKGNAME__VISIBILITY_CONTROL_H_
#define PKGNAME__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PKGNAME_EXPORT __attribute__ ((dllexport))
    #define PKGNAME_IMPORT __attribute__ ((dllimport))
  #else
    #define PKGNAME_EXPORT __declspec(dllexport)
    #define PKGNAME_IMPORT __declspec(dllimport)
  #endif
  #ifdef PKGNAME_BUILDING_LIBRARY
    #define PKGNAME_PUBLIC PKGNAME_EXPORT
  #else
    #define PKGNAME_PUBLIC PKGNAME_IMPORT
  #endif
  #define PKGNAME_PUBLIC_TYPE PKGNAME_PUBLIC
  #define PKGNAME_LOCAL
#else
  #define PKGNAME_EXPORT __attribute__ ((visibility("default")))
  #define PKGNAME_IMPORT
  #if __GNUC__ >= 4
    #define PKGNAME_PUBLIC __attribute__ ((visibility("default")))
    #define PKGNAME_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PKGNAME_PUBLIC
    #define PKGNAME_LOCAL
  #endif
  #define PKGNAME_PUBLIC_TYPE
#endif

#endif  // PKGNAME__VISIBILITY_CONTROL_H_
