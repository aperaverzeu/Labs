#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QtMath>

#include "figure.h"
#include "circle.h"
#include "angle.h"
#include "rectangle.h"
#include "square.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
     void onTimeOut();

private slots:
    void on_btnDrawFigure_clicked();
    void on_btnDrawAngler_clicked();
    void on_btnDrawCircle_clicked();
    void on_btnDrawRectangle_clicked();
    void on_btnDrawSquare_clicked();
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnRotateRight_clicked();
    void on_btnRotateLeft_clicked();

private:
    Ui::MainWindow *ui;

    Figure  *figure;
    Circle   *circle;
    Angle *angler;
    Rectangle *rectangle;
    Square *square;

    enum picture { _figure, _circle, _angler, _rectangle, _square };
    picture now = _figure;

    double angle, percentage;
};
#endif // MAINWINDOW_H
