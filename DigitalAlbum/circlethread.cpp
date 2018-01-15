#include "circlethread.h"

circleThread::circleThread(){}

void circleThread::run()
{
    while (1)
    {
        emit circleSignal();
        //every 7 secs change a pic
        sleep(7);
    }
}
