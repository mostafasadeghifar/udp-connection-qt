#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUdpSocket>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mSocket = new QUdpSocket(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnConnect_clicked()
{
    auto datagram = ui->lnMsg->text().toLatin1();
    mSocket->writeDatagram(datagram,QHostAddress::Broadcast,ui->port->value());
}
