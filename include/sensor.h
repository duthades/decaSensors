#ifndef _SENSOR_H
#define _SENSOR_H
#include <vector>

using namespace std;
namespace sensor {
/** Sensor is the base class for all the sensors.
 */
class Sensor {
   public:
    /// Destructor for the sensor class
    virtual ~Sensor();
    /// pure virtual subscript operator overload.
    virtual vector<double> operator[](char str) = 0;
    /// pure virtual subscript operator overload.
    virtual double operator[](int str) = 0;
};
}  // namespace sensor

#endif
