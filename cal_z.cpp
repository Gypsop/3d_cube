#include "cal_z.h"

/*
float cal_d_A_SApo(float A_x, float A_y, float B_x, float B_y, float S_x, float S_y)
{
    float m = (A_y - B_y) / (A_x - B_x);
    float b = A_y - m * A_x;
    float SApo_x = (m * S_y + S_x - m * b) / (pow(m, 2) + 1);
    float SApo_y = (pow(m, 2) * S_y + m * S_x + b) / (pow(m, 2) + 1);
    return sqrt(pow((A_x - SApo_x), 2) + pow((A_y - SApo_y), 2));
}

float cal_d_A_B(float A_x, float A_y, float B_x, float B_y)
{
    return sqrt(pow((A_x - B_x), 2) + pow((A_y - B_y), 2));
}
*/

/*
==========final remark! 20210617 21:40==========
不能用矩形作为前提！*要用且只能用*平行四边形
所以不存在“投影点是垂线交点”这种说法。正确的理解方式是，S1和S2是某一个边过S的平行线与另一条边的交点，然后只用平行四边形的对角线平分
*/

/*

    A----------------------refB
   /
  *Sn(return)  *S
 /
B

    A-----------*-------------B
   /       Sn(return)
  /           *S
 /
refB

*/


float Sn_x(float A_x, float A_y, float B_x, float B_y, float refB_x, float refB_y, float S_x, float S_y)
{
    float m = (A_y - B_y) / (A_x - B_x);
    float b = A_y - m * A_x;
    float refm = (A_y - refB_y) / (A_x - refB_x);
    float refb_passS = S_y - refm * S_x;
    return ((refb_passS - b) / (m - refm));
}

float Sn_y(float A_x, float A_y, float B_x, float B_y, float refB_x, float refB_y, float S_x, float S_y)
{
    float m = (A_y - B_y) / (A_x - B_x);
    float b = A_y - m * A_x;
    float refm = (A_y - refB_y) / (A_x - refB_x);
    float refb_passS = S_y - refm * S_x;
    return (m * ((refb_passS - b) / (m - refm)) + b);
}

float dxy(float A_x, float A_y, float B_x, float B_y)
{
    return sqrt(pow((A_x - B_x), 2) + pow((A_y - B_y), 2));
}

float cal_z(float A_x, float A_y, float A_z,
            float B_x, float B_y, float B_z,
            float C_x, float C_y, float C_z,
            float D_x, float D_y, float D_z,
            float S_x, float S_y)
{
    // !!rectangle!!(not!!!) *parallelogram* A-B-C-D, clockwise:
    //       A------*-----------------B
    //      /     S2               /
    //     /                      /
    //    *S1   *S               /
    //   /                      /
    //  /                      /
    // D------------------------C

    //**from jiang: calculate S_z  begin**
    /*
    float S_z;
    S_z = A_z
          -
            (A_z-D_z)* ( (S_x-A_x)*(D_x-A_x) + (S_y-A_y)*(D_y-A_y))//dot_product(AS, AD)
                     /
            pow((sqrt(pow(A_x,2)+pow(D_x,2))), 2)
          -
            (A_z-B_z)* ( (S_x-A_x)*(B_x-A_x) + (S_y-A_y)*(B_y-A_y))//dot_product(AS, AB)
                     /
            pow((sqrt(pow(A_x,2)+pow(B_x,2))), 2);
    */
    //**from jiang: calculate S_z  end**

    //**calculate S_z again start**
    /*
    float S_z;
    S_z = A_z -
            (A_z - D_z) * cal_d_A_SApo(A_x, A_y, D_x, D_y, S_x, S_y) / cal_d_A_B(A_x, A_y, D_x, D_y) -
            (A_z - B_z) * cal_d_A_SApo(A_x, A_y, B_x, B_y, S_x, S_y) / cal_d_A_B(A_x, A_y, B_x, B_y);
    */
    //**calculate S_z again end**

    //**calculate S_z again again start**
    /*
    平行四边形A-S2-S-S1的对角线互相平分，Zs1和Zs2可以通过AD和AB边上按比例计算，
    然后通过A-S2-S-S1的对角线交点转换到Za与Zs的关系，从而得到Zs
    */

    float S1_x = Sn_x(A_x, A_y, D_x, D_y, B_x, B_y, S_x, S_y);
    float S1_y = Sn_y(A_x, A_y, D_x, D_y, B_x, B_y, S_x, S_y);
    float S2_x = Sn_x(A_x, A_y, B_x, B_y, D_x, D_y, S_x, S_y);
    float S2_y = Sn_y(A_x, A_y, B_x, B_y, D_x, D_y, S_x, S_y);

    float S1_z = D_z + (A_z - D_z) * dxy(D_x, D_y, S1_x, S1_y) / dxy(D_x, D_y, A_x, A_y);
    float S2_z = B_z + (A_z - B_z) * dxy(B_x, B_y, S2_x, S2_y) / dxy(B_x, B_y, A_x, A_y);

    float SApo_z = 0.5 * (S1_z + S2_z);
    float S_z = A_z + 2.0 * (SApo_z - A_z);

    //**calculate S_z again again end**


    return S_z;
}
