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