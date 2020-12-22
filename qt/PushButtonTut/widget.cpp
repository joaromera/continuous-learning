#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
//    ui->setupUi(this);

    QFont buttonFont("Times", 20, QFont::Bold);

    // Clicking
    QPushButton *button = new QPushButton("Button Click", this);
    button->setMinimumSize(200, 100);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked, [=] {
        qDebug() << "Button clicked";
    });

    // Press and release
    QPushButton *button2 = new QPushButton("Button Press", this);
    button2->setMinimumSize(200, 100);
    button2->move(205, 0);
    button2->setFont(buttonFont);
    connect(button2, &QPushButton::pressed, [=] {
        qDebug() << "Button pressed";
    });

    connect(button2, &QPushButton::released, [=] {
        qDebug() << "Button released";
    });
}

Widget::~Widget()
{
    delete ui;
}

