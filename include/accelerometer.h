#ifndef _ACC_H
#define _ACC_H

#include <vector>
#include "imu.h"
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
class Accelerometer : public Imu {
   public:
    Accelerometer(vector<vector<double>> data_ref);
    ~Accelerometer() = default;
    inline vector<double> get_data() {}


};
}  // namespace sensor

#endif
