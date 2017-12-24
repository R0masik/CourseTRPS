#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <math.h>
#include "field.h"

class Algorithm
{
private:
    // поле моделирования
    Field* field;

public:
    Algorithm() { field = new Field(); }
    ~Algorithm() { delete field; }

    // изменение параметров моделирования
    //  поля
    void setFieldN(int fn)      { field->setN(fn); }
    void setFieldD(double fd)   { field->setD(fd); }
    void setFieldA(double fa)   { field->setA(fa); }
    void setFieldG(double fg)   { field->setG(fg); }

    //  частиц
    void setCorpM(double fm)              { field->setCorpM(fm); }
    void setCorpR(double fr)              { field->setCorpR(fr); }
    void setCorpXi(double fx, int ind)    { field->setCorpXi(fx, ind); }
    void setCorpYi(double fy, int ind)    { field->setCorpYi(fy, ind); }
    void setCorpVXi(double fvx, int ind)  { field->setCorpVXi(fvx, ind); }
    void setCorpVYi(double fvy, int ind)  { field->setCorpVYi(fvy, ind); }

    // получение параметров поля
    int    getFieldN()        { return field->getN(); }
    double getFieldD()        { return field->getD(); }
    double getFieldA()        { return field->getA(); }
    double getFieldG()        { return field->getG(); }
    double getFieldK()        { return field->getK(); }
    double getFieldVmax()     { return field->getVmax(); }

    // получение границ поля
    double getFieldXmin()     { return field->getXmin(); }
    double getFieldXmax()     { return field->getXmax(); }
    double getFieldYmin()     { return field->getYmin(); }
    double getFieldYmax()     { return field->getYmax(); }

    // получение параметров частиц
    double getCorpX(int ind)  { return field->getCorpX(ind); }
    double getCorpY(int ind)  { return field->getCorpY(ind); }
    double getCorpR(int ind)  { return field->getCorpR(ind); }
    double getCorpVX(int ind) { return field->getCorpVX(ind); }
    double getCorpVY(int ind) { return field->getCorpVY(ind); }
    double getCorpM(int ind)  { return field->getCorpM(ind); }

    // пересоздание частиц
    void recreateCorp();

    // вычисление силы взаимодействия между частицами
    // определяемой потенциалом Дж-Л
    double forceLJ(double l);

    // ограничение максимальной скорости частиц
    double outOfV(double v);

    // выполнение итерации моделирования
    void modeling();
};

#endif // ALGORITHM_H
