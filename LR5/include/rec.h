#pragma once
#include <cmath>

#ifdef _WIN32
    #define EXPORT extern "C" __declspec(dllexport)
    #define IMPORT extern "C" __declspec(dllimport)
    #define STDCALL __stdcall
#else
    #define EXPORT extern "C" __attribute__((visibility("default")))
    #define IMPORT extern "C"
    #define STDCALL
#endif

EXPORT int STDCALL countNegSin(double* arr, int left, int right);
