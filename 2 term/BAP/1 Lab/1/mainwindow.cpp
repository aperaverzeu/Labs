#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnUp_clicked()
{
    s->Up();
    repaint();
}

void MainWindow::on_btnDown_clicked()
{
    s->Down();
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    s->DrawShip(&painter);
}
