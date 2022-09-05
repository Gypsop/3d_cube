#include "if_across.h"

bool if_across(float A_x, float A_y,
               float B_x, float B_y,
               float C_x, float C_y,
               float D_x, float D_y,
               float S_x, float S_y
               )
{
    // rectangle A-B-C-D, clockwise:
    // A------------------------B
    // |                      |
    // |                      |
    // |     *S               |
    // |                      |
    // |                      |
    // D------------------------C

    //ref: https://blog.csdn.net/qq_40416052/article/details/99690238

    bool across = false;

    float minX = qMin(qMin(qMin(A_x, B_x), C_x), D_x);
    float maxX = qMax(qMax(qMax(A_x, B_x), C_x), D_x);
    float minY = qMin(qMin(qMin(A_y, B_y), C_y), D_y);
    float maxY = qMax(qMax(qMax(A_y, B_y), C_y), D_y);

    if (S_x < minX || S_x > maxX || S_y < minY || S_y > maxY)
    {
        return false;
    }

    std::vector <Point> points;
    points.push_back(Point(A_x, A_y));
    points.push_back(Point(B_x, B_y));
    points.push_back(Point(C_x, C_y));
    points.push_back(Point(D_x, D_y));
    for (unsigned int i = 0, j = points.size() - 1; i < points.size(); j = i++)
    {
        if ((points[i].y > S_y) != (points[j].y > S_y) &&
                S_x < (points[j].x - points[i].x) * (S_y - points[i].y) / (points[j].y - points[i].y) + points[i].x)
        {
            across = !across;
        }
    }

    return across;

    //上面是新的实现方式！旧的代码实现在下面这个注释，有问题，而且修起来太费脑子，不要了
    /*if (D_x<=S_x&&S_x<=B_x&&A_y>=S_y&&S_y>=C_y) //situation 1
    {
        if ( ((A_x<=S_x&&S_x<=C_x)&&(B_y>=S_y&&S_y>=D_y))||
             ((C_x<=S_x&&S_x<=A_x)&&(D_y>=S_y&&S_y>=B_y))
           )
        across = true;
    }
    else if (B_x<=S_x&&S_x<=D_x&&C_y>=S_y&&S_y>=A_y) //situation 2
    {
        if ( ((C_x<=S_x&&S_x<=A_x)&&(D_y>=S_y&&S_y>=B_y))||
             ((A_x<=S_x&&S_x<=C_x)&&(B_y>=S_y&&S_y>=D_y))
           )
        across = true;
    }
    else if (C_x<=S_x&&S_x<=A_x&&B_y>=S_y&&S_y>=D_y) //situation 3
    {
        if ( ((B_x<=S_x&&S_x<=D_x)&&(A_y>=S_y&&S_y>=C_y))||
             ((D_x<=S_x&&S_x<=B_x)&&(C_y>=S_y&&S_y>=A_y))
           )
        across = true;
    }
    else if (A_x<=S_x&&S_x<=C_x&&D_y>=S_y&&S_y>=B_y) //situation 4
    {
        if ( ((D_x<=S_x&&S_x<=B_x)&&(C_y>=S_y&&S_y>=A_y))||
             ((B_x<=S_x&&S_x<=D_x)&&(A_y>=S_y&&S_y>=C_y))
           )
        across = true;
    }*/
}

