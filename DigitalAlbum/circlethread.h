#ifndef CIRCLETHREAD_H
#define CIRCLETHREAD_H

#include <QThread>

class circleThread : public QThread
{
    Q_OBJECT
public:
    circleThread();
protected:
    void run();
signals:
    void circleSignal();
};

#endif // CIRCLETHREAD_H
