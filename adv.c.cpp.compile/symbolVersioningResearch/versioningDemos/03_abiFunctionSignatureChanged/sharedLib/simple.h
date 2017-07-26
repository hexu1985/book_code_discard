#pragma once

// defined when building the latest client binary
#ifdef SIMPLELIB_VERSION_3_0
int first_function(int x, int normfactor);
#else
int first_function(int x);
#endif // SIMPLELIB_VERSION_3_0

int second_function(int x);
int third_function(int x);

int fourth_function(int x);
int fifth_function(int x);
