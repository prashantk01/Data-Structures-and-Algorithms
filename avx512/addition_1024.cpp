#include <iostream>
#include <immintrin.h>
#include <cassert>
#include <algorithm>

void display(const int *c, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}
// 1. build this code with avx512 flag
// g++ -std=c++14 -mavx512f -o output simd_avx512.cpp
int main()
{
    constexpr int n = 1024;
    alignas(64) int a[n];
    alignas(64) int b[n];
    alignas(64) int c[n];
    alignas(64) int ans[n];

    // init
    for (int i = 0; i < n; i++)
    {
        a[i] = 0 + i;
        b[i] = 2000 + i;
        ans[i] = a[i] + b[i];
    }

    int nLoop = n / 16; // 16 elements in single processing
    for (int i = 0; i < n; i += 16)
    {
        // load values in intrinsic
        __m512i ap = _mm512_load_epi32((void const *)&a[i]); // 1. load
        __m512i bp = _mm512_load_epi32((void const *)&b[i]);
        __m512i cp = _mm512_add_epi32(ap, bp); // 2. add
        _mm512_store_epi32((void *)&c[i], cp); // 3. add
        // add_vec(a, b, c, n);
    }
    // display(c, n);
    assert(std::equal(c, c + n, ans));
    std::cout << "Assertion passed! Results are correct." << std::endl;
    return 0;
}