#ifndef FADEIMGTHREAD_H
#define FADEIMGTHREAD_H

#include <QImage>

#include "pixelcomputethread.h"

class fadeImgThread : public QThread
{
    Q_OBJECT
public:
    QImage A, B;
    fadeImgThread();
protected:
    void run();
private:
    void changeImage();
signals:
    void imgSignal(uchar*);
};

#endif // FADEIMGTHREAD_H
