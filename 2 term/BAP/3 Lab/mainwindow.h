#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "mylist.h"

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
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnInitialize_clicked();
    void on_btnShow_clicked();
    void on_btnAdd_clicked();
    void on_btnSearch_clicked();
    void on_btnDelete_clicked();
    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;

    MyList  list;

    int checkNum(QString str);

};
#endif // MAINWINDOW_H
