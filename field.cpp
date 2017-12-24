#include "field.h"

Field::Field()
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    createCorp();
}

Field::~Field()
{
    deleteCorp();
}

void Field::setCorpM(double fm)
{
    for (int i = 0; i < n; i++)
        corp[i].setM(fm);
}

void Field::setCorpR(double fr)
{
    for (int i = 0; i < n; i++)
        corp[i].setR(fr);
}
