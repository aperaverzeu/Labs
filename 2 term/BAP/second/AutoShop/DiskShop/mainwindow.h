#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include "auto.h"

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
    void on_btnOpen_clicked();
    void on_btnSave_clicked();
    void on_btnAdd_clicked();
    void on_btnShow_clicked();
    void on_btnSearch_clicked();
    void on_btnSort_clicked();
    void on_btnDelete_clicked();
    void on_comboBoxCountry_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QString file_name;

    int size = 0;
    Auto* *a = new Auto*[10000];

    void write(Auto* *a, int size);
};
#endif // MAINWINDOW_H
