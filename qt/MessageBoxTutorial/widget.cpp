#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QMessageBox>
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // Set first button using QMessageBox object
    auto longMessageSetUp = [=] {
        QMessageBox message;
        message.setMinimumSize(300, 200);
        message.setWindowTitle("Message Title");
        message.setText("Something happened");
        message.setInformativeText("Do you want to do something?");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);

        const int ret = message.exec();

        if (ret == QMessageBox::Ok)
            qDebug() << "User clicked OK";
        else if (ret == QMessageBox::Cancel)
            qDebug() << "User clicked CANCEL";
    };

    QPushButton *button = new QPushButton(this);
    button->setText("Click Me");
    button->move(200,200);
    connect(button, &QPushButton::clicked, longMessageSetUp);

    // Set second message using QMessageBox static method
    auto shortMessageSetUp = [=] {
        const int ret = QMessageBox::critical(
            this,
            "Hello",
            "GoodBye my friend this is the end",
            QMessageBox::Ok | QMessageBox::Cancel
        );

        if (ret == QMessageBox::Ok)
            qDebug() << "User clicked OK";
        else if (ret == QMessageBox::Cancel)
            qDebug() << "User clicked CANCEL";
    };

    QPushButton *secondButton = new QPushButton(this);
    secondButton->setText("NO! Click Me!!");
    secondButton->move(300,300);
    connect(secondButton, &QPushButton::clicked, shortMessageSetUp);
}

Widget::~Widget()
{
    delete ui;
}

