#ifndef FIELD_H
#define FIELD_H

#include "corpuscle.h"

class Field
{
private:
    // границы поля моделирования
    double xmin = 0.0;
    double xmax = 1000.0;
    double ymin = 0.0;
    double ymax = 1000.0;

    // параметры моделирования:
    //  ускорение свободного падения
    //  коэффициент гашения удара
    //  максимальная скорость частиц
    double g = 0.04;
    double k = 0.85;
    double vmax = 3;

    // параметры потенциала Леннард-Джонса (Л-Дж)
    double d = 10.0;
    double a = 30.0;

    // количество частиц
    int n = 150;

    // массив частиц
    Corpuscle* corp;

public:
    Field();
    ~Field();

    // создание и удаление массива частиц
    void createCorp() { corp = new Corpuscle[n]; }
    void deleteCorp() { delete[] corp; }

    // запись параметров моделирования:
    //  количество частиц
    //  параметр d потенциала Л-Дж
    //  параметр a потенциала Л-Дж
    //  ускорение свободного падения
    void setN(int fn)    { n = fn; }
    void setD(double fd) { d = fd; }
    void setA(double fa) { a = fa; }
    void setG(double fg) { g = fg; }

    // запись параметров для всех частиц
    void setCorpM(double fm);
    void setCorpR(double fr);

    // запись параметров для частицы
    void setCorpXi(double fx, int ind)    { corp[ind].setX(fx); }
    void setCorpYi(double fy, int ind)    { corp[ind].setY(fy); }
    void setCorpVXi(double fvx, int ind)  { corp[ind].setVX(fvx); }
    void setCorpVYi(double fvy, int ind)  { corp[ind].setVY(fvy); }

    // получение параметров моделирования
    int    getN()       { return n; }
    double getD()       { return d; }
    double getA()       { return a; }
    double getG()       { return g; }
    double getK()       { return k; }
    double getVmax()    { return vmax; }

    // получение границ поля
    double getXmin()    { return xmin; }
    double getXmax()    { return xmax; }
    double getYmin()    { return ymin; }
    double getYmax()    { return ymax; }

    // получение параметров частицы
    double getCorpX(int ind)  { return corp[ind].getX(); }
    double getCorpY(int ind)  { return corp[ind].getY(); }
    double getCorpR(int ind)  { return corp[ind].getR(); }
    double getCorpVX(int ind) { return corp[ind].getVX(); }
    double getCorpVY(int ind) { return corp[ind].getVY(); }
    double getCorpM(int ind)  { return corp[ind].getM(); }
};

#endif // FIELD_H
