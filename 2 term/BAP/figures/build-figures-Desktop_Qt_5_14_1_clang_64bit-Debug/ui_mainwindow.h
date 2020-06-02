/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnRotateRight;
    QPushButton *btnDrawSquare;
    QLabel *labelArea;
    QLabel *labelCircleRadius;
    QGraphicsView *graphicsView;
    QLabel *labelZoom;
    QPushButton *btnDrawFigure;
    QLabel *labelRectangleSidesM;
    QLineEdit *lineEditCircleRadius;
    QPushButton *btnDrawRectangle;
    QLineEdit *lineEditAngR;
    QLabel *labelAngR;
    QPushButton *btnMinus;
    QLabel *labelAngSidesN;
    QLabel *labelRectangleSidesN;
    QLabel *labelRotate;
    QLabel *labelPerimeter;
    QLineEdit *lineEditRectangleSidesN;
    QPushButton *btnDrawAngler;
    QLineEdit *lineEditSquareSides;
    QPushButton *btnPlus;
    QPushButton *btnDrawCircle;
    QLabel *labelSquareSides;
    QPushButton *btnRotateLeft;
    QLineEdit *lineEditAngNumSide;
    QLineEdit *lineEditRectangleSidesM;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1080, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnRotateRight = new QPushButton(centralwidget);
        btnRotateRight->setObjectName(QString::fromUtf8("btnRotateRight"));
        btnRotateRight->setGeometry(QRect(0, 241, 100, 30));
        QFont font;
        font.setPointSize(14);
        btnRotateRight->setFont(font);
        btnDrawSquare = new QPushButton(centralwidget);
        btnDrawSquare->setObjectName(QString::fromUtf8("btnDrawSquare"));
        btnDrawSquare->setGeometry(QRect(0, 411, 200, 30));
        QFont font1;
        font1.setPointSize(13);
        btnDrawSquare->setFont(font1);
        labelArea = new QLabel(centralwidget);
        labelArea->setObjectName(QString::fromUtf8("labelArea"));
        labelArea->setGeometry(QRect(10, 61, 190, 50));
        QFont font2;
        font2.setPointSize(15);
        labelArea->setFont(font2);
        labelArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelCircleRadius = new QLabel(centralwidget);
        labelCircleRadius->setObjectName(QString::fromUtf8("labelCircleRadius"));
        labelCircleRadius->setGeometry(QRect(10, 301, 70, 25));
        labelCircleRadius->setFont(font);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(200, 0, 881, 722));
        graphicsView->setFont(font1);
        labelZoom = new QLabel(centralwidget);
        labelZoom->setObjectName(QString::fromUtf8("labelZoom"));
        labelZoom->setGeometry(QRect(10, 110, 190, 50));
        labelZoom->setFont(font2);
        labelZoom->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnDrawFigure = new QPushButton(centralwidget);
        btnDrawFigure->setObjectName(QString::fromUtf8("btnDrawFigure"));
        btnDrawFigure->setGeometry(QRect(0, 671, 200, 30));
        btnDrawFigure->setFont(font1);
        labelRectangleSidesM = new QLabel(centralwidget);
        labelRectangleSidesM->setObjectName(QString::fromUtf8("labelRectangleSidesM"));
        labelRectangleSidesM->setGeometry(QRect(10, 491, 70, 25));
        labelRectangleSidesM->setFont(font);
        lineEditCircleRadius = new QLineEdit(centralwidget);
        lineEditCircleRadius->setObjectName(QString::fromUtf8("lineEditCircleRadius"));
        lineEditCircleRadius->setGeometry(QRect(80, 301, 110, 25));
        btnDrawRectangle = new QPushButton(centralwidget);
        btnDrawRectangle->setObjectName(QString::fromUtf8("btnDrawRectangle"));
        btnDrawRectangle->setGeometry(QRect(0, 521, 200, 30));
        btnDrawRectangle->setFont(font1);
        lineEditAngR = new QLineEdit(centralwidget);
        lineEditAngR->setObjectName(QString::fromUtf8("lineEditAngR"));
        lineEditAngR->setGeometry(QRect(80, 601, 110, 25));
        labelAngR = new QLabel(centralwidget);
        labelAngR->setObjectName(QString::fromUtf8("labelAngR"));
        labelAngR->setGeometry(QRect(10, 601, 70, 25));
        labelAngR->setFont(font);
        btnMinus = new QPushButton(centralwidget);
        btnMinus->setObjectName(QString::fromUtf8("btnMinus"));
        btnMinus->setGeometry(QRect(100, 161, 100, 30));
        btnMinus->setFont(font);
        labelAngSidesN = new QLabel(centralwidget);
        labelAngSidesN->setObjectName(QString::fromUtf8("labelAngSidesN"));
        labelAngSidesN->setGeometry(QRect(10, 571, 70, 25));
        labelAngSidesN->setFont(font);
        labelRectangleSidesN = new QLabel(centralwidget);
        labelRectangleSidesN->setObjectName(QString::fromUtf8("labelRectangleSidesN"));
        labelRectangleSidesN->setGeometry(QRect(10, 461, 70, 25));
        labelRectangleSidesN->setFont(font);
        labelRotate = new QLabel(centralwidget);
        labelRotate->setObjectName(QString::fromUtf8("labelRotate"));
        labelRotate->setGeometry(QRect(10, 191, 190, 50));
        labelRotate->setFont(font2);
        labelRotate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelPerimeter = new QLabel(centralwidget);
        labelPerimeter->setObjectName(QString::fromUtf8("labelPerimeter"));
        labelPerimeter->setGeometry(QRect(10, 11, 190, 50));
        labelPerimeter->setFont(font2);
        labelPerimeter->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEditRectangleSidesN = new QLineEdit(centralwidget);
        lineEditRectangleSidesN->setObjectName(QString::fromUtf8("lineEditRectangleSidesN"));
        lineEditRectangleSidesN->setGeometry(QRect(80, 461, 110, 25));
        btnDrawAngler = new QPushButton(centralwidget);
        btnDrawAngler->setObjectName(QString::fromUtf8("btnDrawAngler"));
        btnDrawAngler->setGeometry(QRect(0, 631, 200, 30));
        btnDrawAngler->setFont(font1);
        lineEditSquareSides = new QLineEdit(centralwidget);
        lineEditSquareSides->setObjectName(QString::fromUtf8("lineEditSquareSides"));
        lineEditSquareSides->setGeometry(QRect(80, 381, 110, 25));
        btnPlus = new QPushButton(centralwidget);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));
        btnPlus->setGeometry(QRect(2, 161, 100, 30));
        btnPlus->setFont(font);
        btnDrawCircle = new QPushButton(centralwidget);
        btnDrawCircle->setObjectName(QString::fromUtf8("btnDrawCircle"));
        btnDrawCircle->setGeometry(QRect(0, 331, 200, 30));
        btnDrawCircle->setFont(font1);
        labelSquareSides = new QLabel(centralwidget);
        labelSquareSides->setObjectName(QString::fromUtf8("labelSquareSides"));
        labelSquareSides->setGeometry(QRect(10, 381, 70, 25));
        labelSquareSides->setFont(font);
        btnRotateLeft = new QPushButton(centralwidget);
        btnRotateLeft->setObjectName(QString::fromUtf8("btnRotateLeft"));
        btnRotateLeft->setGeometry(QRect(100, 241, 100, 30));
        btnRotateLeft->setFont(font);
        lineEditAngNumSide = new QLineEdit(centralwidget);
        lineEditAngNumSide->setObjectName(QString::fromUtf8("lineEditAngNumSide"));
        lineEditAngNumSide->setGeometry(QRect(80, 571, 110, 25));
        lineEditRectangleSidesM = new QLineEdit(centralwidget);
        lineEditRectangleSidesM->setObjectName(QString::fromUtf8("lineEditRectangleSidesM"));
        lineEditRectangleSidesM->setGeometry(QRect(80, 491, 110, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1080, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnRotateRight->setText(QCoreApplication::translate("MainWindow", "\342\237\263", nullptr));
        btnDrawSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        labelArea->setText(QCoreApplication::translate("MainWindow", "Area: ", nullptr));
        labelCircleRadius->setText(QCoreApplication::translate("MainWindow", "Radius   =", nullptr));
        labelZoom->setText(QCoreApplication::translate("MainWindow", "Zoom:", nullptr));
        btnDrawFigure->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        labelRectangleSidesM->setText(QCoreApplication::translate("MainWindow", "M sides  =", nullptr));
        btnDrawRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        labelAngR->setText(QCoreApplication::translate("MainWindow", "R            =", nullptr));
        btnMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelAngSidesN->setText(QCoreApplication::translate("MainWindow", "N side    =", nullptr));
        labelRectangleSidesN->setText(QCoreApplication::translate("MainWindow", "N sides  =", nullptr));
        labelRotate->setText(QCoreApplication::translate("MainWindow", "Rotate:", nullptr));
        labelPerimeter->setText(QCoreApplication::translate("MainWindow", "Perimeter:", nullptr));
        btnDrawAngler->setText(QCoreApplication::translate("MainWindow", "Ang", nullptr));
        btnPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btnDrawCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        labelSquareSides->setText(QCoreApplication::translate("MainWindow", "N sides  =", nullptr));
        btnRotateLeft->setText(QCoreApplication::translate("MainWindow", "\342\237\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
