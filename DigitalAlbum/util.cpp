#include "util.h"

vector<QImage> util::getImgs(QString file_path, int width, int height)
{
    // get all JPG imgs
    string pattern = file_path.toStdString() + "/*.jpg";
    vector<cv::String> fn;

    glob(pattern, fn, false);

    vector<QImage> images;
    size_t count = fn.size();
    for (size_t i = 0; i < count; i++)
    {
        Mat m = imread(fn[i]);
        // Convert Mat to 4 channel Mat
        cvtColor(m, m, CV_RGB2RGBA, 4);
        images.push_back(cvMat2QImage(m).scaled(width, height));
    }

    return images;
}

QImage util::cvMat2QImage(const Mat& mat)
{
    // Copy input Mat
    const uchar *pSrc = (const uchar*)mat.data;
    // Create QImage with same dimensions as input Mat
    QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
    return image.copy();
}
/*
vector<QImage> util::changeImage(QImage A, QImage B)
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
    vector<QImage> fades;
    for (int fade = 255; fade >0; fade--)
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
        QImage fadeImg(fadeImage, A.width(), A.height(), QImage::Format_ARGB32);
        fades.push_back(fadeImg);
    }
    return fades;
}
*/

//void util::getFadeImage(uchar* A_start, uchar* B_start, int fade, uchar* rowIndex)
//{
//    unsigned int *A_bit = new unsigned int(10);
//    unsigned int *B_bit = new unsigned int(10);

//    for (int i = 0; i < A.width(); i++)
//    {
//        //b
//        *(A_bit) = A_start[i * 4];
//        //g
//        *(A_bit+1) = A_start[i * 4 + 1];
//        //r
//        *(A_bit+2) = A_start[i * 4 + 2];
//        //a
//        *(A_bit+3) = A_start[i * 4 + 3];

//        *(B_bit) = B_start[i * 4];
//        *(B_bit+1) = B_start[i * 4 + 1];
//        *(B_bit+2) = B_start[i * 4 + 2];
//        *(B_bit+3) = B_start[i * 4 + 3];

//        SSE4::getFadePixel(A_bit, B_bit, fade, rowIndex);
//        rowIndex += 4;
//    }
//}

//QImage util::cvMat2QImage(const cv::Mat &m) {
//    return QImage(m.data, m.cols, m.rows, m.step, QImage::Format_RGB888).copy();
//}
