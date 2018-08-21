#ifndef _SOUND_H
#define _SOUND_H

#include <vector>
#include "env.h"
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
/**This class is a container for the sound readings from the json file.
 * The units of the readings are decibels.
 * Base class for the Sound class env.
 */
class Sound : public Env {
   public:
    /// Create a sound class. Has arguments - vector of readings to be stored in
    /// the class object.
    explicit Sound(vector<double> data_ref);
    /// Default destructor for the sound class
    ~Sound() = default;
};
}  // namespace sensor

#endif
