#include "include/gyroscope.h"

namespace sensor {
sensor::Gyroscope::Gyroscope(vector<vector<double>> data_ref) {
    read_data(data_ref);
}

}  // namespace sensor
