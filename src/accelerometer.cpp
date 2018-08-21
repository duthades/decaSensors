#include "include/accelerometer.h"

namespace sensor {
sensor::Accelerometer::Accelerometer(vector<vector<double>> data_ref) {
    read_data(data_ref);
}

}  // namespace sensor
