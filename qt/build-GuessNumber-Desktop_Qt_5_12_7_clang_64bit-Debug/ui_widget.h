/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *nameLabel;
    QSpinBox *spinBox;
    QPushButton *guessButton;
    QLabel *messageLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *startOverButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(403, 287);
        nameLabel = new QLabel(Widget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(20, 10, 367, 57));
        QFont font;
        font.setPointSize(48);
        nameLabel->setFont(font);
        nameLabel->setAlignment(Qt::AlignCenter);
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(40, 90, 141, 41));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10);
        guessButton = new QPushButton(Widget);
        guessButton->setObjectName(QString::fromUtf8("guessButton"));
        guessButton->setGeometry(QRect(200, 88, 171, 45));
        messageLabel = new QLabel(Widget);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setGeometry(QRect(10, 150, 381, 51));
        QFont font1;
        font1.setPointSize(24);
        messageLabel->setFont(font1);
        messageLabel->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 200, 381, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startOverButton = new QPushButton(horizontalLayoutWidget);
        startOverButton->setObjectName(QString::fromUtf8("startOverButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startOverButton->sizePolicy().hasHeightForWidth());
        startOverButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(startOverButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        nameLabel->setText(QApplication::translate("Widget", "Guess my number", nullptr));
        guessButton->setText(QApplication::translate("Widget", "Guess", nullptr));
        messageLabel->setText(QApplication::translate("Widget", "Go on, make your guess...", nullptr));
        startOverButton->setText(QApplication::translate("Widget", "Start over", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
