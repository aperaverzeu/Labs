#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "hashtable.h"

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
    void on_btnAdd_clicked();
    void on_btnSearch_clicked();
    void on_bntDelete_clicked();
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_bntAddInfo_clicked();
    void on_BtnDeleteInfo_clicked();
    void on_btnClear_clicked();
    void on_btnShow_clicked();

    void on_bntTask_clicked();

    void on_bntCreateHashTable_clicked();

private:
    Ui::MainWindow *ui;

    HashTable* HT = new HashTable();

    void printTable();

};
#endif // MAINWINDOW_H
