/*
 * Copyright (c) [2016], [Curt Meyers]
 * All rights reserved.
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include "test.h"
#include "test_thread.h"

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
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_testInitButton_pressed();

    void on_testInitButton_released();

    void on_testStrobeButton_pressed();

    void on_testStrobeButton_released();

    void on_testSelectButton_pressed();

    void on_testSelectButton_released();

    void on_testDataSlider_valueChanged(int value);

    void on_testDataButton_toggled(bool checked);

    void on_testDataValue_overflow();

    void on_testControlButton_toggled(bool checked);

    void on_testControlSlider_valueChanged(int value);

    void on_testWatchdogButton_toggled(bool checked);

    void on_delayBox_valueChanged(int arg1);

    void on_testReadDip_clicked();

    void on_testReadCoin_clicked();

    void on_testReadFlip_clicked();

    void on_testReadMisc_clicked();

    void on_testReadRow_clicked();

    void on_testReadZero_clicked();

    void on_testReadLmpStA_clicked();

    void on_testReadLmpStB_clicked();

    void on_testReadFusTstA_clicked();

    void on_testReadFusTstB_clicked();

public slots:
    void messageBox(const QString messsage);

private:
    Ui::MainWindow *ui;
    Test test;
    //std::thread testThread;
    int testData_;
    int controlData_;
    QThread *pWorkerThread_;
    TestThread *worker;
    long watchdogDelay_;

    void readThis(uint8_t reg);

};

#endif // MAINWINDOW_H
