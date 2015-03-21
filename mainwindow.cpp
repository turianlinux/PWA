#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    argList = QCoreApplication::arguments();

    heightS = argList[1];
    widthS = argList[2];
    title = argList[3];
    file = argList[4];

    height = heightS.toInt();
    width = widthS.toInt();

    setCentralWidget(ui->webView);

    setMaximumHeight(height);
    setMinimumHeight(height);
    setMaximumWidth(width);
    setMinimumWidth(width);

    setWindowTitle(title);

    ui->webView->load(QUrl::fromLocalFile(file));
}

MainWindow::~MainWindow()
{
    delete ui;
}
