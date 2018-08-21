#ifndef _SOUND_H
#define _SOUND_H

#include <vector>
#include "env.h"
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
class Sound : public Env {
   public:
    explicit Sound(vector<double> data_ref);
    ~Sound() = default;
    
    inline vector<double> get_x_data() {}
    inline vector<double> get_y_data() {}
    inline vector<double> get_z_data() {}

};
}  // namespace sensor

#endif
