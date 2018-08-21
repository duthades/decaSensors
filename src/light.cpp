#include "include/light.h"

namespace sensor {
sensor::Light::Light( vector<double> data_ref) : Env(data_ref) {
  //  read_data(data_ref);
}

}  // namespace sensor
/*
int main() {
   vector<double> test{1, 2, 3, 2, 3, 4, 5, 7, 2};
   sensor::Light acc(test);
   sensor::Sensor* sen = &acc;
   cout << sen->get_data().size() << "\n";
   return 0;
}
*/
