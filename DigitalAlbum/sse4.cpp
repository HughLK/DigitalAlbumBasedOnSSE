#include "sse4.h"

void SSE4::getFadePixel(unsigned int *imgA, unsigned int *imgB, int fade, uchar* fade_pixel) {
    __m128i xmm0, xmm1, xmm2, xmm3;

    xmm3 = _mm_setzero_si128();
    xmm0 = _mm_loadu_si128((__m128i*)(imgA));
    xmm1 = _mm_loadu_si128((__m128i*)(imgB));

    xmm1=_mm_sub_epi16(xmm1,xmm0);//minus
    xmm2=_mm_set_epi16(fade,fade,fade,fade,fade,fade,fade,fade);//set fade
    xmm1=_mm_mullo_epi16(xmm1,xmm2);//multi
    xmm1=_mm_srai_epi16(xmm1,7);//move right 8 bit
    xmm1=_mm_add_epi16(xmm1,xmm0);//add
    xmm1=_mm_packus_epi16 (xmm1, xmm3);//compress

    *(fade_pixel) =_mm_extract_epi8(xmm1, 0);//extract 1st int
    *(fade_pixel+1) = _mm_extract_epi8(xmm1, 2);//extract 2nd int
    *(fade_pixel+2) = _mm_extract_epi8(xmm1, 4);//extract 3rd int
    *(fade_pixel+3) = _mm_extract_epi8(xmm1, 6);//extract 4th int
}
