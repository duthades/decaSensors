#ifndef _MAGNETO_H
#define _MAGNETO_H

#include <vector>
#include "accelerometer.h"
#include "imu.h"
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
/**Magnetometer is a sensor from IMU group. Magnetometer inherits from Imu. It
 * has 3 axes x, y, z. The unit of the Magnetometer data is micro Tesla.
 *
 */
class Magnetometer : public Imu {
   public:
    /// Constructor for the Magnetometer class
    explicit Magnetometer(vector<vector<double>> data_ref);
    /// Destructor for the Magnetometer class
    ~Magnetometer() = default;
};
}  // namespace sensor

#endif
