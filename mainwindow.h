#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include "test.h"

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

public slots:
    void messageBox(const QString messsage);


private:
    Ui::MainWindow *ui;
    Test test;
    std::thread testThread;
};

#endif // MAINWINDOW_H
