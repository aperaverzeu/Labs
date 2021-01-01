#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();
    bool getDrawEnable();
    bool getRectangleEnable();
    bool getCircleEnable();
    bool getLineEnable();
    bool getFillEnable();
    QColor getColor();
    int getValueSlider();

public slots:
    void slotDraw();
    void slotRectangle();
    void slotCircle();
    void slotLine();
    void slotFill();
    void slotColor();

    void slotSlider(int x);

private:
    bool drawEnable;
    bool rectangleEnable;
    bool circleEnable;
    bool lineEnable;
    bool fillEnable;
    int valueSlider;
    QColorDialog *colorDialog;
    QColor color;
};
#endif // MAINWINDOW_H
