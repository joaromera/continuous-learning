#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add central widget
    QPushButton *button = new QPushButton("Hello", this);
    setCentralWidget(button);

    // Declare quit action
    QAction *quitAction = new QAction("Quit");
    connect(
        quitAction,
        &QAction::triggered,
        [=] { QApplication::quit(); }
    );


    // Add menus
    menuBar()->setNativeMenuBar(false);
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);

    // Status bar message
    statusBar()->showMessage("Uploading file...", 3000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint()
{
    return QSize(800, 500);
}

