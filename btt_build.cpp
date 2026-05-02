// btt_build.cpp -- BTT library build unit for JUCE/MSVC
// Copyright (c) 2021 Michael Krzyzaniak -- MIT License
//
// This is the ONLY file to add to your Projucer project for BTT.
// Same pattern as how JUCE internally includes sqlite3.

#ifdef _MSC_VER
  #pragma warning(push, 0)    // Suppress most warnings for third-party C code
  // 'push, 0' resets level to 0 but does NOT silence specific level-1
  // warnings like C4702 (unreachable code) -- those still fire because
  // they sit at /W1.  Disable them explicitly so a clean compile of our
  // own code is not buried under upstream noise.
  #pragma warning(disable: 4702)  // unreachable code
#endif

// Undo any macros from JUCE/Windows PCH that clash with BTT identifiers
#ifdef real
  #undef real
#endif
#ifdef imag
  #undef imag
#endif
#ifdef small
  #undef small
#endif
#ifdef near
  #undef near
#endif
#ifdef far
  #undef far
#endif

#include "btt_amalgamation.inc"

#ifdef _MSC_VER
  #pragma warning(pop)
#endif
