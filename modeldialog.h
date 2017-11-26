#ifndef MODELDIALOG_H
#define MODELDIALOG_H

#include "ui_modeldialog.h"

class ModelDialog : public QDialog, private Ui::ModelDialog
{
    Q_OBJECT
public:
    explicit ModelDialog(QWidget *parent = 0);
private slots:
    void on_exitButton_clicked();
    void on_startButton_clicked();
    void on_stopButton_clicked();
};

#endif // MODELDIALOG_H
