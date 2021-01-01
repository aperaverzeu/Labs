#include "size.h"

int Size::length = 750;
int Size::height = 750;

Size::Size(Canvas *canvas) : QWidget() {
    QVBoxLayout *layout = new QVBoxLayout(this);
    lengthLine = new QLineEdit;
    heightLine = new QLineEdit;
    QFormLayout *done = new QFormLayout;

    done->addRow("Enter length (x)", lengthLine);
    done->addRow("Enter height (y)", heightLine);

    create = new QPushButton("Create");
    layout->addLayout(done);
    layout->addWidget(create);
    connect(create, SIGNAL(clicked(bool)), canvas, SLOT(newCanvas()));
    connect(lengthLine, SIGNAL(textChanged(QString)), this, SLOT(getLengthLine(QString)));
    connect(heightLine, SIGNAL(textChanged(QString)), this, SLOT(getHeightLine(QString)));

    connect(create, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void Size::createClick() {
    this->show();
}

void Size::getLengthLine(QString lLine) {
    length = lLine.toInt();
}
void Size::getHeightLine(QString hLine) {
    height = hLine.toInt();
}

int Size::getLength() {
    return length;
}

int Size::getHeight() {
    return height;
}
