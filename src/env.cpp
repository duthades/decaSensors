#include "include/env.h"

namespace sensor {
sensor::Env::Env(vector<double> data_ref) : size(data_ref.size()) {
    read_data(data_ref);
}
void sensor::Env::read_data(vector<double> ref) {
    int size = ref.size();
    x.resize(size);
    auto iter = ref.begin();
    int i = 0;
    for (iter; iter != ref.end(); ++iter, i++) {
        x[i] = (*iter);
    }
    ref.clear();
}
sensor::Env::Env() {}
sensor::Env::~Env() { x.clear(); }
vector<double> sensor::Env::get_data() { return x; }

vector<double> sensor::Env::get_x_data() {};
vector<double> sensor::Env::get_y_data() {};
vector<double> sensor::Env::get_z_data() {};

}  // namespace sensor
/*
int main() {
    vector<double> test{1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    // sensor::Env acc(test);
    sensor::Sensor* sen = new sensor::Env(test);
    int i = 2;
    cout << sen->get_data()[i] << "\n";
    return 0;
}*/
