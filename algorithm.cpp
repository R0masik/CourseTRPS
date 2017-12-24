#include "algorithm.h"

void Algorithm::recreateCorp()
{
    field->deleteCorp();
    field->createCorp();
}

double Algorithm::forceLJ(double l)
{

    double t1 = getFieldD() / getFieldA();
    double t2 = getFieldA() / l;
    return t1 * (pow(t2, 13) - pow(t2, 7));
}

double Algorithm::outOfV(double v)
{
    double vmax = getFieldVmax();
    if (abs(v) > vmax) {
        if (v > 0)
            return vmax;
        else
            return -vmax;
    }
    else
        return v;
}

void Algorithm::modeling()
{
    int n = getFieldN();
    for (int i = 0; i < n; i++) {
        double px = getCorpX(i);    // координата х
        double py = getCorpY(i);    // координата у
        double r =  getCorpR(i);    // радиус частицы
        double vx = getCorpVX(i);   // проекция скорости на ось х
        double vy = getCorpVY(i);   // проекция скорости на ось у
        double m =  getCorpM(i);    // масса частицы

        // вычисление новых скоростей частиц

        // влияние гравитационного воздействия
        vy -= getFieldG();

        // вычисление силы взаимодействия с другими частицами
        double f, fx, fy;
        f = fx = fy = 0;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double rx = px - getCorpX(j);
                double ry = py - getCorpY(j);
                double l = sqrt(rx * rx + ry * ry);

                if (l < 2 * getFieldA()) {
                    f += forceLJ(l);
                    fx += f * rx / l;
                    fy += f * ry / l;
                }
            }
        }

        vx += fx / m;
        vy += fy / m;

        // проверка превышения частицей максимальной скорости
        vx = outOfV(vx);
        vy = outOfV(vy);

        double xmin = getFieldXmin();
        double xmax = getFieldXmax();
        double ymin = getFieldYmin();
        double ymax = getFieldYmax();

        // проверка вылета частицы за границы поля
        if (px + vx >= xmax - r || px + vx <= xmin + r) {
            if (px + vx >= xmax - r)
                // px = xmax - r - (px + vx - xmax + r) =
                px = 2 * xmax - 2 * r - px - vx;
            else
                // px = xmin + r - (xmin + r - px - vx) =
                px = px + vx;
            vx -= 2 * vx;
            if (px + vx <= xmax - r && px + vx >= xmin + r)
                vx *= getFieldK();;
        }

        if (py + vy >= ymax - r || py + vy <= ymin + r) {
            if (py + vy >= ymax - r)
                // py = ymax - r - (py + vy - ymax + r) =
                py = 2 * ymax - 2 * r - py - vy;
            else
                // py = ymin + r - (ymin + r - py - vy) =
                py = py + vy;
            vy -= 2 * vy;
            if (py + vy <= ymax - r && py + vy >= ymin + r)
                vy *= getFieldK();;
        }

        // новые координаты частицы
        px += vx;
        py += vy;

        // запись в частицы новых координат и скоростей
        setCorpXi(px, i);
        setCorpYi(py, i);
        setCorpVXi(vx, i);
        setCorpVYi(vy, i);
    }
}
