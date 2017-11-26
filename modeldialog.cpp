#include "modeldialog.h"

ModelDialog::ModelDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void ModelDialog::on_exitButton_clicked()
{
    close();
}

void ModelDialog::on_startButton_clicked()
{
    glWidget -> timerStart(40);
}

void ModelDialog::on_stopButton_clicked()
{
    glWidget -> timerStop();
}
