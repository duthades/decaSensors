#ifndef _LIGHT_H
#define _LIGHT_H

#include <vector>
#include "env.h"
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
class Light : public Env {
   public:
    explicit Light(vector<double> data_ref);
    ~Light() = default;
    inline vector<double> get_x_data() {}
    inline vector<double> get_y_data() {}
    inline vector<double> get_z_data() {}

};
}  // namespace sensor

#endif
