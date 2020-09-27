#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditQueue->setReadOnly(true);
    ui->lineEditFront->setReadOnly(true);
    ui->lineEditBack->setReadOnly(true);
    QPixmap bkgnd("/Users/Alex/Documents/Education/Labs/2 term/BAP/fifth/QProject/background/nature clouds down the fudziyama.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnqPush_clicked()
{
    int no_of_numbers = 31;
    int first_number = -32;

   // int random = std::rand() % no_of_numbers + (first_number);
  // int random = (std::rand() % no_of_numbers + 1 - first_number) + first_number;
    int random = first_number + (int)((double)(no_of_numbers - first_number) * (rand() / (RAND_MAX + 1.0)));


    q.push(random);
    ui->lineEditQueue->setText(q.output());
}

void MainWindow::on_btnqPop_clicked()
{
    q.pop();
    ui->lineEditQueue->setText(q.output());
}

void MainWindow::on_btnFront_clicked()
{
    ui->lineEditFront->setText(QString::number(q.front()));
}

void MainWindow::on_btnBack_clicked()
{
    ui->lineEditBack->setText(QString::number(q.back()));
}

void MainWindow::positive(Queue* q)
{
    std::list<int> v;
    while (!q->isEmpty()) {
        if (q->front() > 0) {
            v.push_back(q->front());
            q->pop();
        } else if (q->front() <= 0) {
            q->pop();
        }
    }
    while (!v.empty()) {
        q->push(v.front());
        v.pop_front();
    }
}

void MainWindow::on_btnPosotive_clicked()
{
    positive(&q);
    ui->lineEditQueue->setText(q.output());
}
