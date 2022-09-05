#ifndef CAL_Z_H
#define CAL_Z_H

#include <cmath>

float Sn_x(float A_x, float A_y, float B_x, float B_y, float refB_x, float refB_y, float S_x, float S_y);
float Sn_y(float A_x, float A_y, float B_x, float B_y, float refB_x, float refB_y, float S_x, float S_y);
float dxy(float A_x, float A_y, float B_x, float B_y);
float cal_z(float A_x, float A_y, float A_Z,
            float B_x, float B_y, float B_Z,
            float C_x, float C_y, float C_Z,
            float D_x, float D_y, float D_Z,
            float S_x, float S_y);

#endif // CAL_Z_H
