// Copyright (c) 2022 OUXT Polaris
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PKGNAME__VISIBILITY_CONTROL_H_
#define PKGNAME__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define PKGNAME_EXPORT __attribute__((dllexport))
#define PKGNAME_IMPORT __attribute__((dllimport))
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
#define PKGNAME_EXPORT __attribute__((visibility("default")))
#define PKGNAME_IMPORT
#if __GNUC__ >= 4
#define PKGNAME_PUBLIC __attribute__((visibility("default")))
#define PKGNAME_LOCAL __attribute__((visibility("hidden")))
#else
#define PKGNAME_PUBLIC
#define PKGNAME_LOCAL
#endif
#define PKGNAME_PUBLIC_TYPE
#endif

#endif  // PKGNAME__VISIBILITY_CONTROL_H_
