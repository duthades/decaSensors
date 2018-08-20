#ifndef _GYRO_H
#define _GYRO_H

#include <vector>
#include "imu.h"
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
class Gyroscope : public Imu {
   public:
    Gyroscope(vector<vector<double>> data_ref);
    ~Gyroscope() = default;
};
}  // namespace sensor

#endif
