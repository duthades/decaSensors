#ifndef _LIGHT_H
#define _LIGHT_H

#include <vector>
#include "env.h"
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
/** Light class is a cointainer to store data from light the unit is lux.
 * */
class Light : public Env {
   public:
    /// Constructor for the Light class
    explicit Light(vector<double> data_ref);
    /// Destructor for the Light class
    ~Light() = default;
};
}  // namespace sensor

#endif
