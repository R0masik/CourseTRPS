#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include "ui_helpdialog.h"

class HelpDialog : public QDialog, private Ui::HelpDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = 0);

public slots:
    void on_exitButton_clicked();
};

#endif // HELPDIALOG_H
