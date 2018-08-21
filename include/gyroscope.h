#ifndef _GYRO_H
#define _GYRO_H

#include <vector>
#include "imu.h"
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
/**Gyroscope is a sensor from IMU group. Gyroscope inherits from Imu. It has 3
 * axes x, y, z. The unit of the Gyroscope data is radian per second.
 *
 */
class Gyroscope : public Imu {
   public:
    /// Constrctor for the Gyroscope class. Take a vector as input and stores it
    /// in to the cointainer.
    explicit Gyroscope(vector<vector<double>> data_ref);
    /// default destructor for the Gyroscope class.
    ~Gyroscope() = default;
};
}  // namespace sensor

#endif
