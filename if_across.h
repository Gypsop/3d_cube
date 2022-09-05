#ifndef IF_ACROSS_H
#define IF_ACROSS_H

#include <QDebug>
#include <cmath>
#include <QtGlobal>
#include <vector>

class Point
{
public:
    float x, y;
    Point(float x, float y) : x(x), y(y) {}
};

bool if_across(float A_x, float A_y,
               float B_x, float B_y,
               float C_x, float C_y,
               float D_x, float D_y,
               float S_x, float S_y
               );

#endif // IF_ACROSS_H
