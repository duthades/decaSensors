#ifndef _ENV_H
#define _ENV_H

#include <vector>
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
class Env : public Sensor {
    int size;
    std::vector<double> x;

   public:
    Env(std::vector<double> data_ref);
    ~Env();
    
    void read_data(std::vector<double> ref);
    vector<double> get_data();
    inline vector<double> get_x_data(){};
    inline vector<double> get_y_data(){};
    inline vector<double> get_z_data(){};
    double operator[](int str);
    inline vector<double> operator[](char str){};
};
}  // namespace sensor

#endif
