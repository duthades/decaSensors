#include "include/sound.h"

namespace sensor {
sensor::Sound::Sound( vector<double> data_ref) : Env(data_ref) {
//    read_data(data_ref);
}

}  // namespace sensor
   /*
   int main() {
       vector<vector<double>> test{{1, 2, 3}, {2, 3, 4}, {5, 7, 2}};
       sensor::Sound acc(test);
       sensor::Sensor* sen = &acc;
       cout << sen->get_x_data().size() << "\n";
       return 0;
   }
   */
