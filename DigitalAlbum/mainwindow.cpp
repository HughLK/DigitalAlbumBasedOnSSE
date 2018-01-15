#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();

    c = new circleThread;
    connect(c, SIGNAL(circleSignal()), this, SLOT(circleSlot()));

    t = new fadeImgThread;
    connect(t, SIGNAL(imgSignal(uchar*)), this, SLOT(imgSwitch(uchar*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    current_path = QDir::currentPath();

    //set default path to the combobox
    ui->directoryComboBox->addItem(current_path);

    height = ui->imgLabel->height();
    width = ui->imgLabel->width();

    //get imgs in current directory
    imgs = util::getImgs(current_path, width, height);

    //show first pic
    showImg();
}

void MainWindow::on_browseBtn_clicked()
{
    QString directory = QDir::toNativeSeparators( QFileDialog::getExistingDirectory( this, tr("Save Path"), QDir::currentPath() ) );

    if (!directory.isEmpty())
    {
        if (ui->directoryComboBox->findText(directory) == -1)
        {
            ui->directoryComboBox->addItem(directory);
        }
        //show new directory in combo box
        ui->directoryComboBox->setCurrentIndex(ui->directoryComboBox->findText(directory));
    }

    imgs = util::getImgs(ui->directoryComboBox->currentText(), width ,height);

    if (!imgs.size())
    {
        //If there is no pic in current directory,clear shown pic
        ui->imgLabel->clear();
    }
    else
    {
        //reset pics_index cause of a new directory selected
        pics_index = 0;
        showImg();
    }
}

void MainWindow::on_nextBtn_clicked()
{
    if (imgs.size())
    {
        t->B = imgs[pics_index];
        pics_index = (pics_index + 1) % imgs.size();
        t->A = imgs[pics_index];
        t->start();
    }
}

void MainWindow::on_preBtn_clicked()
{
    if (imgs.size())
    {
        t->B = imgs[pics_index];
        pics_index = pics_index == 0 ? pics_index + imgs.size() - 1: pics_index - 1;
        t->A = imgs[pics_index];
        t->start();
    }
}

void MainWindow::showImg()
{
    //show images in default path if there's an image exists
    if (imgs.size() != 0)
    {
        ui->imgLabel->setPixmap(QPixmap::fromImage(imgs[pics_index]));
    }
}

void MainWindow::showImg(QImage img)
{
    ui->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::imgSwitch(uchar *fadeImg)
{
    QImage fadeImage(fadeImg, width, height, QImage::Format_ARGB32);
    showImg(fadeImage);
}

void MainWindow::circleSlot()
{
    on_nextBtn_clicked();
}

void MainWindow::on_circleBtn_toggled(bool checked)
{
    if (checked)
    {
        c->start();
    }
    else
    {
        c->terminate();
    }
}
