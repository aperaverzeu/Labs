#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <random>
#include "queue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnqPush_clicked();
    void on_btnqPop_clicked();
    void on_btnFront_clicked();
    void on_btnBack_clicked();

    void on_btnPosotive_clicked();

private:
    Ui::MainWindow *ui;

    Queue q;
    Queue qAns;

    void positive(Queue* q);
};
#endif // MAINWINDOW_H
