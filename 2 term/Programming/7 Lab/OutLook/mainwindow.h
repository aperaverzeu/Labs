#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    void on_btnEditUserInfo_clicked();
    void on_btnShowUserInfo_clicked();
    void on_btnAddTask_clicked();
    void on_btnShowAddTask_clicked();
    void on_bntShowTask_clicked();
    void on_btnShowBirthday_clicked();

private:
    Ui::MainWindow *ui;

    QVector<QVector<QString>> users;
    QVector<QVector<QString>> tasks;
};
#endif // MAINWINDOW_H
