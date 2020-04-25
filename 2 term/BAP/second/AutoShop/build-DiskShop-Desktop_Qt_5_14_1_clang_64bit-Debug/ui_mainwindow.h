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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QPushButton *btnAdd;
    QPushButton *btnShow;
    QPushButton *btnDelete;
    QPushButton *btnSort;
    QPushButton *btnSearch;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCountry;
    QComboBox *comboBoxCountry;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelMotorType;
    QComboBox *comboBoxMotorType;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelMark;
    QComboBox *comboBoxMark;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelPrice;
    QComboBox *comboBoxPrice;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditEat;
    QLineEdit *lineEditDur;
    QLineEdit *lineEditCon;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelEat;
    QLabel *labelDur;
    QLabel *labelCon;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 0, 561, 291));
        btnOpen = new QPushButton(centralwidget);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setGeometry(QRect(620, 30, 121, 31));
        btnOpen->setCursor(QCursor(Qt::ArrowCursor));
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(620, 70, 121, 31));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(620, 220, 121, 31));
        btnShow = new QPushButton(centralwidget);
        btnShow->setObjectName(QString::fromUtf8("btnShow"));
        btnShow->setGeometry(QRect(620, 180, 121, 31));
        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setGeometry(QRect(630, 480, 111, 31));
        btnSort = new QPushButton(centralwidget);
        btnSort->setObjectName(QString::fromUtf8("btnSort"));
        btnSort->setGeometry(QRect(630, 440, 111, 31));
        btnSearch = new QPushButton(centralwidget);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setGeometry(QRect(620, 260, 121, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 310, 341, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelCountry = new QLabel(layoutWidget);
        labelCountry->setObjectName(QString::fromUtf8("labelCountry"));

        horizontalLayout->addWidget(labelCountry);

        comboBoxCountry = new QComboBox(layoutWidget);
        comboBoxCountry->addItem(QString());
        comboBoxCountry->addItem(QString());
        comboBoxCountry->addItem(QString());
        comboBoxCountry->setObjectName(QString::fromUtf8("comboBoxCountry"));
        comboBoxCountry->setEditable(false);

        horizontalLayout->addWidget(comboBoxCountry);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 370, 341, 26));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelMotorType = new QLabel(layoutWidget1);
        labelMotorType->setObjectName(QString::fromUtf8("labelMotorType"));

        horizontalLayout_3->addWidget(labelMotorType);

        comboBoxMotorType = new QComboBox(layoutWidget1);
        comboBoxMotorType->addItem(QString());
        comboBoxMotorType->addItem(QString());
        comboBoxMotorType->setObjectName(QString::fromUtf8("comboBoxMotorType"));

        horizontalLayout_3->addWidget(comboBoxMotorType);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 340, 341, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelMark = new QLabel(layoutWidget2);
        labelMark->setObjectName(QString::fromUtf8("labelMark"));

        horizontalLayout_2->addWidget(labelMark);

        comboBoxMark = new QComboBox(layoutWidget2);
        comboBoxMark->addItem(QString());
        comboBoxMark->addItem(QString());
        comboBoxMark->addItem(QString());
        comboBoxMark->addItem(QString());
        comboBoxMark->setObjectName(QString::fromUtf8("comboBoxMark"));

        horizontalLayout_2->addWidget(comboBoxMark);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 400, 341, 26));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelPrice = new QLabel(layoutWidget3);
        labelPrice->setObjectName(QString::fromUtf8("labelPrice"));

        horizontalLayout_4->addWidget(labelPrice);

        comboBoxPrice = new QComboBox(layoutWidget3);
        comboBoxPrice->addItem(QString());
        comboBoxPrice->addItem(QString());
        comboBoxPrice->addItem(QString());
        comboBoxPrice->addItem(QString());
        comboBoxPrice->setObjectName(QString::fromUtf8("comboBoxPrice"));

        horizontalLayout_4->addWidget(comboBoxPrice);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(210, 425, 151, 111));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditEat = new QLineEdit(layoutWidget4);
        lineEditEat->setObjectName(QString::fromUtf8("lineEditEat"));

        verticalLayout->addWidget(lineEditEat);

        lineEditDur = new QLineEdit(layoutWidget4);
        lineEditDur->setObjectName(QString::fromUtf8("lineEditDur"));

        verticalLayout->addWidget(lineEditDur);

        lineEditCon = new QLineEdit(layoutWidget4);
        lineEditCon->setObjectName(QString::fromUtf8("lineEditCon"));

        verticalLayout->addWidget(lineEditCon);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(30, 430, 171, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelEat = new QLabel(layoutWidget5);
        labelEat->setObjectName(QString::fromUtf8("labelEat"));

        verticalLayout_2->addWidget(labelEat);

        labelDur = new QLabel(layoutWidget5);
        labelDur->setObjectName(QString::fromUtf8("labelDur"));

        verticalLayout_2->addWidget(labelDur);

        labelCon = new QLabel(layoutWidget5);
        labelCon->setObjectName(QString::fromUtf8("labelCon"));

        verticalLayout_2->addWidget(labelCon);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "AutoShop", nullptr));
        btnOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        btnShow->setText(QCoreApplication::translate("MainWindow", "Show All", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        btnSort->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        btnSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        labelCountry->setText(QCoreApplication::translate("MainWindow", "Country", nullptr));
        comboBoxCountry->setItemText(0, QCoreApplication::translate("MainWindow", "Belarus", nullptr));
        comboBoxCountry->setItemText(1, QCoreApplication::translate("MainWindow", "Germany", nullptr));
        comboBoxCountry->setItemText(2, QCoreApplication::translate("MainWindow", "USA", nullptr));

        labelMotorType->setText(QCoreApplication::translate("MainWindow", "Motor Type", nullptr));
        comboBoxMotorType->setItemText(0, QCoreApplication::translate("MainWindow", "diesel", nullptr));
        comboBoxMotorType->setItemText(1, QCoreApplication::translate("MainWindow", "gas", nullptr));

        labelMark->setText(QCoreApplication::translate("MainWindow", "Mark", nullptr));
        comboBoxMark->setItemText(0, QCoreApplication::translate("MainWindow", "MAZ", nullptr));
        comboBoxMark->setItemText(1, QCoreApplication::translate("MainWindow", "MAN", nullptr));
        comboBoxMark->setItemText(2, QCoreApplication::translate("MainWindow", "Boar", nullptr));
        comboBoxMark->setItemText(3, QCoreApplication::translate("MainWindow", "Cat", nullptr));

        labelPrice->setText(QCoreApplication::translate("MainWindow", "Price           less then($)", nullptr));
        comboBoxPrice->setItemText(0, QCoreApplication::translate("MainWindow", "10000", nullptr));
        comboBoxPrice->setItemText(1, QCoreApplication::translate("MainWindow", "20000", nullptr));
        comboBoxPrice->setItemText(2, QCoreApplication::translate("MainWindow", "30000", nullptr));
        comboBoxPrice->setItemText(3, QCoreApplication::translate("MainWindow", "50000", nullptr));

        labelEat->setText(QCoreApplication::translate("MainWindow", "Consumption", nullptr));
        labelDur->setText(QCoreApplication::translate("MainWindow", "Durability", nullptr));
        labelCon->setText(QCoreApplication::translate("MainWindow", "Convienience", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
