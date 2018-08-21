#include "include/imu.h"

namespace sensor {
sensor::Imu::Imu(vector<vector<double>> data_ref) : size(data_ref.size()) {
    read_data(data_ref);
}
void sensor::Imu::read_data(vector<vector<double>> ref) {
    int size = ref.size();
    x.resize(size);
    y.resize(size);
    z.resize(size);
    auto iter = ref.begin();
    int i = 0;
    for (iter; iter != ref.end(); ++iter, i++) {
        x[i] = (*iter)[0];
        y[i] = (*iter)[1];
        z[i] = (*iter)[2];
    }
}
sensor::Imu::Imu() {}
sensor::Imu::~Imu() {}
vector<double> sensor::Imu::get_x_data() { return x; }
vector<double> sensor::Imu::get_y_data() { return y; }
vector<double> sensor::Imu::get_z_data() { return z; }
vector<double> sensor::Imu::operator[](char str) {
    if (str == 'x')
        return x;
    else if (str == 'y')
        return y;
    else if (str == 'z')
        return z;
}

}  // namespace sensor
