#include "widget.h"
#include "ui_widget.h"

#include <QtDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // First Name
    QLabel* firstNameLabel = new QLabel("First Name", this);
    firstNameLabel->setMinimumSize(70, 50);
    firstNameLabel->move(10, 10);

    QLineEdit* firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200, 50);
    firstNameLineEdit->move(100, 10);

    // Last Name
    QLabel* lastNameLabel = new QLabel("Last Name", this);
    lastNameLabel->setMinimumSize(70, 50);
    lastNameLabel->move(10, 70);

    QLineEdit* lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200, 50);
    lastNameLineEdit->move(100, 70);

    // City Name
    QLabel* cityLabel = new QLabel("City", this);
    cityLabel->setMinimumSize(70, 50);
    cityLabel->move(10, 130);

    QLineEdit* cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200, 50);
    cityLineEdit->move(100, 130);
    cityLineEdit->setPlaceholderText("Where do you live?");

    // Set button
    QFont buttonFont("Times", 14, QFont::Bold);
    QPushButton* button = new QPushButton("Grab data", this);
    button->setFont(buttonFont);
    button->move(100, 190);

    connect(button, &QPushButton::clicked, [=] {
        QString firstName   = firstNameLineEdit->text();
        QString lastName    = lastNameLineEdit->text();
        QString city        = cityLineEdit->text();

        if (!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty())
        {
            qDebug() << "First Name is: " << firstName;
            qDebug() << "Last Name is: " << lastName;
            qDebug() << "City is: " << city;
        }
        else
        {
            qDebug() << "All fields must be filled!";
        }
    });

    // Cursor position changed
    connect(
        firstNameLineEdit,
        &QLineEdit::cursorPositionChanged,
        [=] { qDebug() << "Cursor position: " << firstNameLineEdit->cursorPosition(); }
    );

    // Editing finished
    connect(
        firstNameLineEdit,
        &QLineEdit::editingFinished,
        [=] { qDebug() << "Editing finished"; }
    );

    // Returned pressed
    connect(
        firstNameLineEdit,
        &QLineEdit::returnPressed,
        [=] { qDebug() << "Return pressed!!!!!!!!!!"; }
    );

    // Selection changed
    connect(
        firstNameLineEdit,
        &QLineEdit::selectionChanged,
        [=] { qDebug() << "...selection changed."; }
    );

    // Text changed
    connect(
        firstNameLineEdit,
        &QLineEdit::textChanged,
        [=] { qDebug() << "Text has changed to: " << firstNameLineEdit->text(); }
    );

    // Text edited
    connect(
        firstNameLineEdit,
        &QLineEdit::textEdited,
        [=] { qDebug() << "Text has been edited to: " << firstNameLineEdit->text(); }
    );
}

Widget::~Widget()
{
    delete ui;
}

