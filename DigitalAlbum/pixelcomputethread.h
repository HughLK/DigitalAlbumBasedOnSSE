#ifndef PIXELCOMPUTETHREAD_H
#define PIXELCOMPUTETHREAD_H

#include <QRunnable>
#include <QThread>
#include <QThreadPool>

#include "sse4.h"

class pixelComputeThread : public QRunnable
{
public:
    pixelComputeThread();
    pixelComputeThread(uchar*, uchar*, int, uchar*, int);

private:
    uchar* A_start;
    uchar* B_start;
    int fade;
    uchar* rowIndex;
    int width;

protected:
    void run();

signals:
    void changeImage();
    void getFadeImage(uchar*, uchar*, int, uchar*);
};

#endif // PIXELCOMPUTETHREAD_H
