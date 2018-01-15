#include "pixelcomputethread.h"
#include "util.h"

pixelComputeThread::pixelComputeThread(uchar* A_start, uchar* B_start, int fade, uchar* rowIndex, int width)
{
    this->A_start = A_start;
    this->B_start = B_start;
    this->fade = fade;
    this->rowIndex = rowIndex;
    this->width = width;
}

void pixelComputeThread::run()
{
    getFadeImage(A_start, B_start, fade, rowIndex);
}

void pixelComputeThread::getFadeImage(uchar* A_start, uchar* B_start, int fade, uchar* rowIndex)
{
    unsigned int *A_bit = new unsigned int(10);
    unsigned int *B_bit = new unsigned int(10);

    for (int i = 0; i < width; i++)
    {
        //b
        *(A_bit) = A_start[i * 4];
        //g
        *(A_bit+1) = A_start[i * 4 + 1];
        //r
        *(A_bit+2) = A_start[i * 4 + 2];
        //a
        *(A_bit+3) = A_start[i * 4 + 3];

        *(B_bit) = B_start[i * 4];
        *(B_bit+1) = B_start[i * 4 + 1];
        *(B_bit+2) = B_start[i * 4 + 2];
        *(B_bit+3) = B_start[i * 4 + 3];

        SSE4::getFadePixel(A_bit, B_bit, fade, rowIndex);
        rowIndex += 4;
    }
}
