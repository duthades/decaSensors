#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <cmath>
#include <vector>
#include "include/accelerometer.h"
#include "include/gyroscope.h"
#include "include/magnetometer.h"
/// This function is used to calculate roll, pitch and yaw of the sensor. This
/// is calculated using Accelerometer and Magnetometer data.
vector<vector<double>> roll_pitch_yaw(sensor::Accelerometer& acc,
                                      sensor::Magnetometer& magneto);
/// This function is used to calculate the steps taken by the person. This is
/// calculated using the Accelerometer data.
int get_steps(sensor::Accelerometer& acc);

#endif
