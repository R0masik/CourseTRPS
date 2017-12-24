#ifndef MODELDIALOG_H
#define MODELDIALOG_H

#include <QTextCodec>
#include <QMessageBox>
#include "ui_modeldialog.h"

class ModelDialog : public QDialog, private Ui::ModelDialog
{
    Q_OBJECT

private:
    // ���������� ������� ����� ���������� � ��������� ����
    QDoubleValidator *dVal;
    QIntValidator *iVal;

public:
    explicit ModelDialog(QWidget *parent = 0);
    ~ModelDialog();

    void check(QLineEdit *edit);

private slots:
    void on_exitButton_clicked();
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_commitButton_clicked();
};

#endif // MODELDIALOG_H
