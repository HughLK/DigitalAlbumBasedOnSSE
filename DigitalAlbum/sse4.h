#ifndef SSE4_H
#define SSE4_H

#include <mmintrin.h> //MMX
#include <xmmintrin.h> //SSE(include mmintrin.h)
#include <emmintrin.h> //SSE2(include xmmintrin.h)
#include <pmmintrin.h> //SSE3(include emmintrin.h)
#include <tmmintrin.h>//SSSE3(include pmmintrin.h)
#include <smmintrin.h>//SSE4.1(include tmmintrin.h)
#include <nmmintrin.h>//SSE4.2(include smmintrin.h)

#include <QImage>

class SSE4
{
public:
    SSE4();

    static void getFadePixel(unsigned int*, unsigned int*, int, uchar*);
};

#endif // SSE4_H
