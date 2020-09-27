#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Figures");
    setFixedSize(1080,720);

    QPixmap bkgnd("/Users/Alex/Documents/Education/Labs/2 term/BAP/figures/figures/background/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    timer->start(300);

    figure = new Figure();
    ui->graphicsView->setScene(figure);
    figure->build();
    figure->setSceneRect(0, 0, 1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnDrawFigure_clicked()
{
    figure = new Figure();
    figure->showCenter = true;
    ui->graphicsView->setScene(figure);
    figure->setSceneRect(0, 0, 1, 1);
    figure->build();
    now = _figure;
}

void MainWindow::on_btnDrawAngler_clicked()
{
    angler = new Angle();
    angler->showCenter = true;
    ui->graphicsView->setScene(angler);
    angler->setSceneRect(0,0,1,1);
    angler->build(ui->lineEditAngNumSide->text().toUInt(), ui->lineEditAngR->text().toDouble() *30);
    now = _angler;
}

void MainWindow::on_btnDrawCircle_clicked()
{
    circle = new Circle();
    circle->showCenter = true;
    ui->graphicsView->setScene(circle);
    circle->setSceneRect(0,0,1,1);
    circle->build(ui->lineEditCircleRadius->text().toDouble() *30);
    now = _circle;
}

void MainWindow::on_btnDrawRectangle_clicked()
{
    rectangle = new Rectangle();
    rectangle->showCenter = true;
    ui->graphicsView->setScene(rectangle);
    rectangle->setSceneRect(0,0,1,1);
    rectangle->build(ui->lineEditRectangleSidesN->text().toDouble() * 30, ui->lineEditRectangleSidesM->text().toDouble() * 30);
    now = _rectangle;
}

void MainWindow::on_btnDrawSquare_clicked()
{
    square = new Square();
    square->showCenter = true;
    ui->graphicsView->setScene(square);
    square->setSceneRect(0,0,1,1);
    square->build(ui->lineEditSquareSides->text().toDouble() * 30);
    now = _square;
}

void MainWindow::on_btnPlus_clicked()
{
    percentage = 1.1;
    switch(now) {
        case _figure:
            figure->zoom(percentage);
            break;
        case _angler:
            angler->zoom(percentage);
            break;
        case _rectangle:
            rectangle->zoom(percentage);
            break;
        case _square:
            square->zoom(percentage);
            break;
        case _circle:
            circle->zoom(percentage);
            break;
    }

}

void MainWindow::on_btnMinus_clicked()
{
    percentage = 0.90909;
    switch(now) {
        case _figure:
            figure->zoom(percentage);
            break;
        case _angler:
            angler->zoom(percentage);
            break;
        case _rectangle:
            rectangle->zoom(percentage);
            break;
        case _square:
            square->zoom(percentage);
            break;
        case _circle:
            circle->zoom(percentage);
            break;
    }
}

void MainWindow::on_btnRotateRight_clicked()
{
    angle = 30 * M_PI / 180;
    switch(now){
        case _figure:
            figure->rotate(angle);
            break;
        case _angler:
            angler->rotate(angle);
            break;
        case _rectangle:
            rectangle->rotate(angle);
            break;
        case _square:
            square->rotate(angle);
            break;
        case _circle:
            circle->rotate(angle);
            break;
    }
}

void MainWindow::on_btnRotateLeft_clicked()
{
    angle = -30 * M_PI / 180;
    switch(now){
        case _figure:
            figure->rotate(angle);
            break;
        case _angler:
            angler->rotate(angle);
            break;
        case _rectangle:
            rectangle->rotate(angle);
            break;
        case _square:
            square->rotate(angle);
            break;
        case _circle:
            circle->rotate(angle);
            break;
    }
}

void MainWindow::onTimeOut()
{
    switch(now){
        case _figure:
            if (!figure->canDraw) {
                ui->labelPerimeter->setText("Perimeter:       " + QString::number(figure->Perimeter()));
                ui->labelArea->setText("Area:                " + QString::number(figure->Area()));
            }
        break;
        case _angler:
            if (!angler->canDraw) {
                ui->labelPerimeter->setText("Perimeter:       " + QString::number(angler->Perimeter()));
                ui->labelArea->setText("Area:                " + QString::number(angler->Area()));
            }
            break;
        case _rectangle:
            if (!angler->canDraw) {
                ui->labelPerimeter->setText("Perimeter:       " + QString::number(rectangle->Perimeter()));
                ui->labelArea->setText("Area:                " + QString::number(rectangle->Area()));
            }
            break;
        case _square:
            if (!angler->canDraw) {
                ui->labelPerimeter->setText("Perimeter:       " + QString::number(square->Perimeter()));
                ui->labelArea->setText("Area:                " + QString::number(square->Area()));
            }
            break;
        case _circle:
            if (!circle->canDraw) {
                ui->labelPerimeter->setText("Perimeter:       " + QString::number(circle->Perimeter()));
                ui->labelArea->setText("Area:                " + QString::number(circle->Area()));
            }
            break;
    }
}
