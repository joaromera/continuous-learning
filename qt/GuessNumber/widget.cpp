#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <stdlib.h>
#include <time.h>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(static_cast<int>(time(nullptr)));
    secretNumber = rand() % 10 + 1;
    qDebug() << "Secret Number generated: " << QString::number(secretNumber);

    ui->startOverButton->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    guessedNumber = ui->spinBox->value();
    qDebug() << "Guessed Number: " << QString::number(guessedNumber);

    if (guessedNumber == secretNumber)
    {
        ui->messageLabel->setText("Congratulations!");
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }
    else
    {
        if (secretNumber < guessedNumber)
        {
            ui->messageLabel->setText("Number is lower than that");
        }
        else
        {
            ui->messageLabel->setText("Number is higher than that");
        }
    }

    ui->messageLabel->repaint();
}

void Widget::on_startOverButton_clicked()
{
    ui->startOverButton->setDisabled(true);
    ui->guessButton->setDisabled(false);

    ui->messageLabel->setText("Go on... guess!");

    secretNumber = rand() % 10 + 1;
    qDebug() << "Secret Number generated: " << QString::number(secretNumber);

    this->repaint();
}
