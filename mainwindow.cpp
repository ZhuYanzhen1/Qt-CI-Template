#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    ui->progressBar->setValue(0);
    testTimer = new QTimer(this);
    connect (testTimer,SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timeTimer = new QTimer(this);
    connect (timeTimer,SIGNAL(timeout()), this, SLOT(timeTimerUpdate()));
    timeTimer->start(1000);
    ui->label_2->setText(QTime::currentTime().toString ("hh:mm:ss"));
}

MainWindow::~MainWindow() {
    delete ui;
    delete testTimer;
    delete timeTimer;
}

void MainWindow::on_pushButton_clicked() {
    QMessageBox::information(NULL, "Hello", "Hello World!");
}

void MainWindow::on_pushButton_2_clicked() {
    ui->progressBar->setValue(0);
    testTimer->start(10);
}

void MainWindow::timeTimerUpdate() {
    QTime time = QTime::currentTime();
    QString text = time.toString ("hh:mm:ss");
    ui->label_2->setText(text);
}

void MainWindow::timerUpdate() {
    if(ui->progressBar->value() == 100)
        testTimer->stop();
    ui->progressBar->setValue(ui->progressBar->value() + 1);
}
