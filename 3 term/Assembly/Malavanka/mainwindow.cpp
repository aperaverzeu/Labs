#include "mainwindow.h"
#include "size.h"
#include "canvas.h"

MainWindow::MainWindow() {
    resize(750,750);
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    lineEnable = 0;
    valueSlider = 1;


    Canvas *canvas = new Canvas(this);
    Size *size = new Size(canvas);
    setCentralWidget(canvas);

    QMenu *menuFile = menuBar()->addMenu("File");

    QAction *actionNew = new QAction("New",this);
    menuFile->addAction(actionNew);
    QAction *actionSave = new QAction("Save",this);
    menuFile->addAction(actionSave);
    QAction *actionOpen = new QAction("Open",this);
    menuFile->addAction(actionOpen);

    connect(actionNew, SIGNAL(triggered(bool)), size, SLOT(createClick()));
    connect(actionSave,SIGNAL(triggered(bool)),canvas,SLOT(saveCanvas()));
    connect(actionOpen,SIGNAL(triggered(bool)),canvas,SLOT(openCanvas()));

    QMenu *menuForm = menuBar()->addMenu("&Form");

    QAction *actionDraw = new QAction("Draw",this);
    menuForm->addAction(actionDraw);
    QAction *actionRectangle = new QAction("Rectangle",this);
    menuForm->addAction(actionRectangle);
    QAction *actionCircle = new QAction("Circle",this);
    menuForm->addAction(actionCircle);
    QAction *actionLine = new QAction("Line",this);
    menuForm->addAction(actionLine);


    connect(actionDraw,SIGNAL(triggered(bool)),this,SLOT(slotDraw()));
    connect(actionRectangle,SIGNAL(triggered(bool)),this,SLOT(slotRectangle()));
    connect(actionCircle,SIGNAL(triggered(bool)),this,SLOT(slotCircle()));
    connect(actionLine,SIGNAL(triggered(bool)),this,SLOT(slotLine()));

    QMenu *menuTools = menuBar()->addMenu("Tools");

    QAction *actionFill = new QAction("Fill",this);
    menuTools->addAction(actionFill);
    QAction *actionReturn = new QAction("Return",this);
    actionReturn->setShortcut(QKeySequence("Ctrl+Z"));
    menuTools->addAction(actionReturn);

    connect(actionFill,SIGNAL(triggered(bool)),this,SLOT(slotFill()));
    connect(actionReturn,SIGNAL(triggered(bool)),canvas,SLOT(returnCanvas()));

    QToolBar *toolBar = addToolBar("Color");

    QPushButton *buttonColor = new QPushButton;
    buttonColor->setText("Color");
    colorDialog = new QColorDialog;
    toolBar->addWidget(buttonColor);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(1,15);
    toolBar->addWidget(slider);

    connect(buttonColor,SIGNAL(clicked(bool)),this,SLOT(slotColor()));
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(slotSlider(int)));
}

bool MainWindow::getDrawEnable() {
    return drawEnable;
}

bool MainWindow::getRectangleEnable() {
    return rectangleEnable;
}

bool MainWindow::getCircleEnable() {
    return circleEnable;
}

bool MainWindow::getLineEnable() {
    return lineEnable;
}

bool MainWindow::getFillEnable() {
    return fillEnable;
}

QColor MainWindow::getColor() {
    return color;
}
int MainWindow::getValueSlider() {
    return valueSlider;
}

void MainWindow::slotDraw() {
    drawEnable = 1;
    rectangleEnable = 0;
    circleEnable = 0;
    fillEnable = 0;
    lineEnable = 0;
}
void MainWindow::slotRectangle() {
    drawEnable = 0;
    rectangleEnable = 1;
    circleEnable = 0;
    fillEnable = 0;
    lineEnable = 0;
}
void MainWindow::slotCircle() {
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 1;
    fillEnable = 0;
    lineEnable = 0;
}
void MainWindow::slotFill() {
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    fillEnable = 1;
    lineEnable = 0;
}

void MainWindow::slotLine() {
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    fillEnable = 0;
    lineEnable = 1;
}

void MainWindow::slotColor() {
    color = colorDialog->getColor();
}

void MainWindow::slotSlider(int x) {
    valueSlider = x;
}

