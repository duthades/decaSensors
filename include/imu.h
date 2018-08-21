#ifndef _IMU_H
#define _IMU_H

#include <vector>
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
class Imu : public Sensor {
    int size;
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
   public:
    Imu(vector<vector<double>> data_ref);
    ~Imu();
    Imu();
    void read_data(vector<vector<double>> ref);
    vector<double> get_x_data();
    vector<double> get_y_data();
    vector<double> get_z_data();
    inline vector<double> get_data() {};

};
}  // namespace sensor

#endif
