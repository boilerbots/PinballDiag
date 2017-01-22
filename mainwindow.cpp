/*
 * Copyright (c) [2016], [Curt Meyers]
 * All rights reserved.
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtWidgets>
#include <QMessageBox>
#include <thread>
#include "test_thread.h"

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

void MainWindow::on_testDataSlider_valueChanged(int value)
{
  testData_ = value;
  if (ui->testDataButton->isChecked()) {
    test.hw.writeDataOnly(1 << testData_);
  }
}

void MainWindow::on_testDataButton_toggled(bool checked)
{
  if (checked) {
    test.hw.portOut();
    test.hw.writeDataOnly(1 << testData_);
  }
  else {
    test.hw.writeDataOnly(0);
    test.hw.portIn();
  }
}

void MainWindow::on_testDataValue_overflow()
{

}

void MainWindow::on_testControlButton_toggled(bool checked)
{
    if (checked) {
      test.hw.control(controlData_);
    }
}

void MainWindow::on_testControlSlider_valueChanged(int value)
{
    controlData_ = value;
    if (ui->testControlButton->isChecked()) {
      test.hw.control(controlData_);
      test.hw.writeData(0, (value == 5) ? 10000:0); // decoder output will generate a pulse
    }
}

void MainWindow::on_testWatchdogButton_toggled(bool checked)
{
  if (checked) {
    pWorkerThread_ = new QThread;
    worker = new TestThread(&test.hw);
    worker->setWatchdogDelay(watchdogDelay_);

    worker->moveToThread(pWorkerThread_);
    connect(pWorkerThread_, SIGNAL(started()), worker, SLOT(doWork()));
    connect(worker, SIGNAL(finished()), pWorkerThread_, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(pWorkerThread_, SIGNAL(finished()), pWorkerThread_, SLOT(deleteLater()));
    pWorkerThread_->start();

    //qDebug() << "Toggle test ON";
  }
  else {
    //qDebug() << "Toggle test OFF";
    worker->keepRunning = false;
    pWorkerThread_->quit();
    pWorkerThread_->wait();
  }
}

void MainWindow::on_delayBox_valueChanged(int arg1)
{
    watchdogDelay_ = arg1;
    worker->setWatchdogDelay(arg1);
}

void MainWindow::readThis(uint8_t reg)
{
  uint8_t result;
  test.hw.control(reg);
  test.hw.readData(&result);
  //ui->readBack->display((int)result);
  QString result_str;
  result_str = QString("0X%1").arg(result,2,16,QLatin1Char('0'));
  //QTextStream(&result_str) << "0x" << result;
  ui->readBackText->setText(result_str);
}

void MainWindow::on_testReadDip_clicked()
{
  readThis(0x2);
}

void MainWindow::on_testReadCoin_clicked()
{
  readThis(0x0);
}

void MainWindow::on_testReadFlip_clicked()
{
  readThis(0x1);
}

void MainWindow::on_testReadMisc_clicked()
{
  readThis(0x3);
}

void MainWindow::on_testReadRow_clicked()
{
  readThis(0x4);
}

void MainWindow::on_testReadZero_clicked()
{
  readThis(0xF);
}

void MainWindow::on_testReadLmpStA_clicked()
{
  readThis(0x10);
}

void MainWindow::on_testReadLmpStB_clicked()
{
  readThis(0x11);
}

void MainWindow::on_testReadFusTstA_clicked()
{
  readThis(0x12);
}

void MainWindow::on_testReadFusTstB_clicked()
{
  readThis(0x13);
}
