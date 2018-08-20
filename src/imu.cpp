#include "include/imu.h"

namespace sensor {
sensor::Imu::Imu( vector<vector<double>> data_ref) : size(data_ref.size()) {
    read_data(data_ref);
}
void sensor::Imu::read_data( vector<vector<double>> ref) {
    int size = ref.size();
    acc_x.resize(size);
    acc_y.resize(size);
    acc_z.resize(size);
    auto iter = ref.begin();
    int i = 0;
    for (iter; iter != ref.end(); ++iter, i++) {
        acc_x[i] = (*iter)[0];
        acc_y[i] = (*iter)[1];
        acc_z[i] = (*iter)[2];
    }
    ref.clear();
}
sensor::Imu::Imu() {}
sensor::Imu::~Imu() {
acc_x.clear();
acc_y.clear();
acc_z.clear();
}
vector<double> sensor::Imu::get_x_data() { return acc_x; }
vector<double> sensor::Imu::get_y_data() { return acc_y; }
vector<double> sensor::Imu::get_z_data() { return acc_z; }
}  // namespace sensor
   /*
   int main() {
       vector<vector<double>> test{{1, 2, 3}, {2, 3, 4}, {5, 7, 2}};
       // sensor::Imu acc(test);
       sensor::Sensor* sen = new sensor::Imu(test);
       int i = 2;
       cout << sen->get_x_data()[i] << "\n";
       cout << sen->get_y_data()[i] << "\n";
       cout << sen->get_z_data()[i] << "\n";
       return 0;
   }
   */
