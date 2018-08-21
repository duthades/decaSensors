#ifndef _ACC_H
#define _ACC_H

#include <vector>
#include "imu.h"
#include "json_wrapper.h"
#include "magnetometer.h"
#include "sensor.h"

namespace sensor {
/**This class is a container for the Accelerometer readings imported from the
 * json file. The units of the readings are meter per second squared. Has 3 axes
 *  x, y, z. The base class for the Accelerometer class is Imu.
 */
class Accelerometer : public Imu {
   public:
    /// Constructor for the class.
    /// Takes a 2d vector as inputs to store in the object.
    explicit Accelerometer(vector<vector<double>> data_ref);

    /// Default destructor for the Accelerometer class.
    ~Accelerometer() = default;
};
}  // namespace sensor

#endif
