#include "fadeimgthread.h"
#include <iostream>

fadeImgThread::fadeImgThread(){}

void fadeImgThread::changeImage()
{
//    //Get head address of QImage(32-bit per pixel)
//    uchar* A_start = A.bits();
//    uchar* B_start = B.bits();

//    for (int fade = 255; fade >= 0; fade--)
//    {
//        getFadeImage(A_start, B_start, fade, 1, );
//    }

    //set up thread pool
    QThreadPool threadPool;
    threadPool.setMaxThreadCount(200);

    uchar* fadeImage = new uchar[A.width() * A.height() * 4];
//    vector<QImage> fades;
    for (int fade = 128; fade >=0; fade--)
    {
        //calculate img from start
//        int fade = 1;
        for (int row = 0; row < A.height(); row++)
        {
            //head address of A and B in designated row
            uchar* A_start = A.scanLine(row);
            uchar* B_start = B.scanLine(row);

//            getFadeImage(A_start, B_start, fade, fadeImage + row * A.width() * 4);
            pixelComputeThread *task = new pixelComputeThread(A_start, B_start, fade, fadeImage + row * A.width() * 4, A.width());

            //get all fade pixels in a line
            threadPool.start(task);
        }
//        QImage fadeImg(fadeImage, A.width(), A.height(), QImage::Format_ARGB32);
        emit imgSignal(fadeImage);
    }
}

void fadeImgThread::run()
{
    changeImage();
}
