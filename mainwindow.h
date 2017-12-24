#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "helpdialog.h"
#include "modeldialog.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

private:
    HelpDialog *help;
    ModelDialog *model;

public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void on_exitButton_clicked();
    void on_helpButton_clicked();
    void on_startButton_clicked();
};

#endif // MAINWINDOW_H
