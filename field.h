#ifndef FIELD_H
#define FIELD_H

#include "corpuscle.h"

class Field
{
private:
    // ������� ���� �������������
    double xmin = 0.0;
    double xmax = 1000.0;
    double ymin = 0.0;
    double ymax = 1000.0;

    // ��������� �������������:
    //  ��������� ���������� �������
    //  ����������� ������� �����
    //  ������������ �������� ������
    double g = 0.04;
    double k = 0.85;
    double vmax = 3;

    // ��������� ���������� �������-������ (�-��)
    double d = 10.0;
    double a = 30.0;

    // ���������� ������
    int n = 150;

    // ������ ������
    Corpuscle* corp;

public:
    Field();
    ~Field();

    // �������� � �������� ������� ������
    void createCorp() { corp = new Corpuscle[n]; }
    void deleteCorp() { delete[] corp; }

    // ������ ���������� �������������:
    //  ���������� ������
    //  �������� d ���������� �-��
    //  �������� a ���������� �-��
    //  ��������� ���������� �������
    void setN(int fn)    { n = fn; }
    void setD(double fd) { d = fd; }
    void setA(double fa) { a = fa; }
    void setG(double fg) { g = fg; }

    // ������ ���������� ��� ���� ������
    void setCorpM(double fm);
    void setCorpR(double fr);

    // ������ ���������� ��� �������
    void setCorpXi(double fx, int ind)    { corp[ind].setX(fx); }
    void setCorpYi(double fy, int ind)    { corp[ind].setY(fy); }
    void setCorpVXi(double fvx, int ind)  { corp[ind].setVX(fvx); }
    void setCorpVYi(double fvy, int ind)  { corp[ind].setVY(fvy); }

    // ��������� ���������� �������������
    int    getN()       { return n; }
    double getD()       { return d; }
    double getA()       { return a; }
    double getG()       { return g; }
    double getK()       { return k; }
    double getVmax()    { return vmax; }

    // ��������� ������ ����
    double getXmin()    { return xmin; }
    double getXmax()    { return xmax; }
    double getYmin()    { return ymin; }
    double getYmax()    { return ymax; }

    // ��������� ���������� �������
    double getCorpX(int ind)  { return corp[ind].getX(); }
    double getCorpY(int ind)  { return corp[ind].getY(); }
    double getCorpR(int ind)  { return corp[ind].getR(); }
    double getCorpVX(int ind) { return corp[ind].getVX(); }
    double getCorpVY(int ind) { return corp[ind].getVY(); }
    double getCorpM(int ind)  { return corp[ind].getM(); }
};

#endif // FIELD_H
