#include "include/magnetometer.h"

namespace sensor {
sensor::Magnetometer::Magnetometer(vector<vector<double>> data_ref) {
    read_data(data_ref);
}

}  // namespace sensor
