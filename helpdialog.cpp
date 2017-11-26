#include "helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void HelpDialog::on_exitButton_clicked()
{
    close();
    delete this;
}
