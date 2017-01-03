#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtWidgets>
#include <QMessageBox>
#include <thread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), test(0x378)
{
  ui->setupUi(this);
  //connect(&test, SIGNAL(myMessage(QString)), this, SLOT(messageBox(QString)), Qt::BlockingQueuedConnection);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
  QMessageBox::question(this, "Question", "Proceed?");
}

void MainWindow::messageBox(const QString messsage)
{
  QMessageBox::information(this,"Message", "Start Test");
}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{
    test.init();
}

void MainWindow::on_testInitButton_pressed()
{
    test.hw.setInit(true);
}

void MainWindow::on_testInitButton_released()
{
    test.hw.setInit(false);
}

void MainWindow::on_testStrobeButton_pressed()
{
    test.hw.setStrobe(true);
}


void MainWindow::on_testStrobeButton_released()
{
    test.hw.setStrobe(false);
}

void MainWindow::on_testSelectButton_pressed()
{
    test.hw.setSelect(true);
}

void MainWindow::on_testSelectButton_released()
{
    test.hw.setSelect(false);
}
