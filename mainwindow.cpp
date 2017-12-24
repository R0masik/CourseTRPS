#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_helpButton_clicked()
{
    help = new HelpDialog(this);
    help->show();
}

void MainWindow::on_startButton_clicked()
{
    model = new ModelDialog(this);
    model->show();
}
