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

void MainWindow::on_pushButton_clicked()
{
  testThread = std::thread (&Test::testPort, &test);

  //test.setNextTest(1);
  //test.start();
  //foo.join();
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
    test.terminate();
    testThread.join();
}

void MainWindow::on_pushButton_4_clicked()
{
    test.init();
}
