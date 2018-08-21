#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <cmath>
#include <vector>
#include "include/accelerometer.h"
#include "include/gyroscope.h"


vector<vector<double>> roll_pitch_yaw(sensor::Accelerometer acc, sensor::Gyroscope gyro);

#endif
