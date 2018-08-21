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
sensor::Env::~Env() {}
vector<double> sensor::Env::get_data() { return x; }
double sensor::Env::operator[](int index) { return x[index]; }
}  // namespace sensor
