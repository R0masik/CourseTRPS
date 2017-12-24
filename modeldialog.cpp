#include "modeldialog.h"

ModelDialog::ModelDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    QLocale locale(QLocale::English);

    // ��������� ������� �����
    dVal = new QDoubleValidator(this);
    dVal->setDecimals(3);
    dVal->setLocale(locale);

    iVal = new QIntValidator(1, 500, this);
    iVal->setLocale(locale);

    mEdit->setValidator(dVal);
    rEdit->setValidator(dVal);
    nEdit->setValidator(iVal);
    dEdit->setValidator(dVal);
    aEdit->setValidator(dVal);
    gEdit->setValidator(dVal);

    // ��������� ��������� �������������
    double mInit = 1000;
    double rInit = 10;
    int nInit = 150;
    double dInit = 10;
    double aInit = 30;
    double gInit = 0.04;

    // ����� ��������� ���������� �������������
    mEdit->setText(QString::number(mInit));
    rEdit->setText(QString::number(rInit));
    nEdit->setText(QString::number(nInit));
    dEdit->setText(QString::number(dInit));
    aEdit->setText(QString::number(aInit));
    gEdit->setText(QString::number(gInit));
}

ModelDialog::~ModelDialog()
{
    delete iVal;
    delete dVal;
}

void ModelDialog::check(QLineEdit *edit)
{
    double dmin = 0.001;
    double dmax = 1000000000000.0;
    double val = edit->text().toDouble();

    if (val < dmin)
        edit->setText(QString::number(dmin));
    else if (val > dmax)
        edit->setText(QString::number(dmax));
}

void ModelDialog::on_exitButton_clicked()
{
    close();
    delete this;
}

void ModelDialog::on_startButton_clicked()
{
    // ������ �������������
    glWidget->timerStart(5);
}

void ModelDialog::on_stopButton_clicked()
{
    // ��������� �������������
    glWidget->timerStop();
}

void ModelDialog::on_commitButton_clicked()
{
    on_stopButton_clicked();

    // �������� ������������ �����
    check(mEdit);
    check(rEdit);
    check(dEdit);
    check(aEdit);
    check(gEdit);

    // �������� ����� ���������� �������������
    // ��������� ����
    glWidget -> setFieldN(nEdit->text().toInt());
    glWidget -> setFieldD(dEdit->text().toDouble());
    glWidget -> setFieldA(aEdit->text().toDouble());
    glWidget -> setFieldG(gEdit->text().toDouble());

    // ��������� ������
    glWidget -> recreateCorp();
    glWidget -> setCorpM(mEdit->text().toDouble());
    glWidget -> setCorpR(rEdit->text().toDouble());

    // ����� ��������������� ��������� � �������� ����������
    QMessageBox::information(0, QTextCodec::codecForLocale()->toUnicode("���������"),
                                QTextCodec::codecForLocale()->toUnicode("��������� �������!"));
}
