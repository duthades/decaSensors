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
    Env(vector<double> data_ref);
    ~Env();
    Env();
    void read_data(vector<double> ref);
    vector<double> get_data();
    virtual vector<double> get_x_data() ;
    virtual vector<double> get_y_data() ;
    virtual vector<double> get_z_data() ;
};
}  // namespace sensor

#endif
