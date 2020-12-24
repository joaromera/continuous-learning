#include "widget.h"
#include "ui_widget.h"

#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QFont labelFont("Times", 10, QFont::Bold);
    QLabel* mLabel = new QLabel("This is my text", this);
    mLabel->setFont(labelFont);
    mLabel->move(100,25);

    QTextEdit* textEdit = new QTextEdit(this);
    textEdit->move(35, 55);

    // Signals
    connect(
        textEdit,
        &QTextEdit::textChanged,
        [=]{ qDebug() << "Text changed"; }
    );

    // Copy Cut Paste Buttons and Signals
    QPushButton* copyButton = new QPushButton("Copy", this);
    copyButton->setMinimumSize(50,25);
    copyButton->move(10,250);
    connect(copyButton, &QPushButton::clicked, [=] {
        textEdit->copy();
    });

    QPushButton* cutButton = new QPushButton("Cut", this);
    cutButton->setMinimumSize(50,25);
    cutButton->move(110,250);
    connect(cutButton, &QPushButton::clicked, [=] {
        textEdit->cut();
    });

    QPushButton* pasteButton = new QPushButton("Paste", this);
    pasteButton->setMinimumSize(50,25);
    pasteButton->move(210,250);
    connect(pasteButton, &QPushButton::clicked, [=] {
        textEdit->paste();
    });

    // Undo redo
    QPushButton* undoButton = new QPushButton("Undo", this);
    undoButton->setMinimumSize(50,25);
    undoButton->move(10, 280);
    connect(undoButton, &QPushButton::clicked, [=] {
        textEdit->undo();
    });

    QPushButton* redoButton = new QPushButton("Redo", this);
    redoButton->setMinimumSize(50,25);
    redoButton->move(110, 280);
    connect(redoButton, &QPushButton::clicked, [=] {
        textEdit->redo();
    });

    // Set text and html to the text edit
    QPushButton* plainTextButton = new QPushButton("Plain Text", this);
    plainTextButton->setMinimumSize(100, 25);
    plainTextButton->move(10, 310);
    connect(plainTextButton, &QPushButton::clicked, [=] {
        textEdit->setPlainText("HEY HEY HEY");
    });

    QPushButton* htmlButton = new QPushButton("Html", this);
    htmlButton->setMinimumSize(100, 25);
    htmlButton->move(120, 310);
    connect(htmlButton, &QPushButton::clicked, [=] {
        textEdit->setHtml("<h1>HELLO</h1><p>Bye!</br>");
    });

    // Grab plain text
    QPushButton* grabText = new QPushButton("Grab Text", this);
    grabText->setMinimumSize(100, 25);
    grabText->move(10, 340);
    connect(grabText, &QPushButton::clicked, [=] {
        qDebug() << textEdit->toPlainText();
    });

    QPushButton* htmlText = new QPushButton("Grab Html", this);
    htmlText->setMinimumSize(100, 25);
    htmlText->move(120, 340);
    connect(htmlText, &QPushButton::clicked, [=] {
        qDebug() << textEdit->toHtml();
    });

    setFixedSize(400,400);
}

Widget::~Widget()
{
    delete ui;
}

