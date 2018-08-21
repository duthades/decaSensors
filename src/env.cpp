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
