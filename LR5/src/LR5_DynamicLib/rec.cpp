#include "rec.h"
#include <cmath>

EXPORT int STDCALL countNegSin(double* arr, int left, int right)
{
    if (left > right) return 0;

    int mid = (left + right) / 2;
    int count = (sin(arr[mid] / 2.0) < 0) ? 1 : 0;
    return count + countNegSin(arr, left, mid - 1) + countNegSin(arr, mid + 1, right);
}
