#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>

#include "util.h"
#include "fadeimgthread.h"
#include "circlethread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_browseBtn_clicked();

    void on_nextBtn_clicked();

    void on_preBtn_clicked();

    void on_circleBtn_toggled(bool checked);

public slots:
    void imgSwitch(uchar*);
    void circleSlot();
private:
    Ui::MainWindow *ui;

    fadeImgThread *t;
    circleThread *c;

    vector<QImage> imgs;

    int width;
    int height;

    unsigned int pics_index = 0;
    QString current_path;

    void init();
    void showImg();
    void showImg(QImage);
};

#endif // MAINWINDOW_H
