#ifndef _MAGNETO_H
#define _MAGNETO_H

#include <vector>
#include "imu.h"
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
class Magnetometer : public Imu {
   public:
    Magnetometer(vector<vector<double>> data_ref);
    ~Magnetometer() = default;
};
}  // namespace sensor

#endif
