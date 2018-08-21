#ifndef _IMU_H
#define _IMU_H

#include <string>
#include <vector>
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
/** Imu class inherits from the Sensor class. Basicly the IMU is a group of
 * sensors mainly accelerometer, gyroscope and magnetometer. These sensors has 3
 * axes x, y, z. This class is a base class for Accelerometer, Gyroscope and
 * Magnetometer class.
 */
class Imu : public Sensor {
    /// size of the container
    int size;
    /// container for the Imu's member sensor's x axis
    std::vector<double> x;
    /// container for the Imu's member sensor's y axis
    std::vector<double> y;
    /// container for the Imu's member sensor's z axis
    std::vector<double> z;

   public:
    /// Constructor for the Imu class. Takes a 2d vector as input and stores
    /// them in the cointainer.
    explicit Imu(vector<vector<double>> data_ref);
    /// destructor for the imu class
    ~Imu();
    /// default class for the Imu class
    Imu();
    /// A function to convert the 2d vector to the respective x, y, z axes
    /// container
    void read_data(vector<vector<double>> ref);
    /// subscript overload to access the individual axis'
    vector<double> operator[](char str);
    inline double operator[](int str){};
};
}  // namespace sensor

#endif
