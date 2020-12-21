# Notes

## Signals and slots

```c++
// widget.h
private slots:
    void changeText();

// widget.cpp
// inside widget's constructor
connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(changeText()));

// another option
connect(ui->pushButton, &QPushButton::clicked, this, &Widget::changeText);

// yet another option
connect(ui->pushButton, &QPushButton::clicked, [=](){
    ui->label->setText("New text");
});
```

## QWidget

https://doc.qt.io/qt-6/qwidget.html

Base class of all user interface objects. A widget that is not embedded in a parent widget is called a window.

## QMainWindow

Usually can contain: menu bar, toolbars, dock widgets, central widget, status bars... This class provides a main application window. Provides a framework for building an application's user interface. Can add to it QToolBars, QDockWdigets, QMenuBar, QStatusBar.


