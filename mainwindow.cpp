#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), test(0x378, this)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  //QMessageBox::information(this,"Message", "Start Test");
  test.start();
}

void MainWindow::on_pushButton_2_clicked()
{
  QMessageBox::question(this, "Question", "Proceed?");
}
