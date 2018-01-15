#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <QImage>

using namespace std;
using namespace cv;

class util
{
public:
    util();

    static vector<QImage> getImgs(QString, int, int);
    static QImage cvMat2QImage(const Mat&);
//    static void getFadeImage(uchar*, uchar*, int, uchar*);
};

#endif // UTIL_H
