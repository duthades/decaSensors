#ifndef _ENV_H
#define _ENV_H

#include <vector>
#include "json_wrapper.h"
#include "sensor.h"

namespace sensor {
/** Env is a class inherits for the class Sensor. This class is the base class
 * for the environment releated sensor data such as light and sound data.
 */
class Env : public Sensor {
    /// size of the container.
    int size;
    /// cointainer to store the sensor data
    std::vector<double> x;

   public:
    /// Constructor for the Env class
    explicit Env(std::vector<double> data_ref);
    /// Distructor for teh Env class
    ~Env();
    /// Read data form the vector from the parameter ref and stores in the its
    /// object's cointainer.
    void read_data(std::vector<double> ref);
    /// subscript operator oveload for the derived classes. can access value at
    /// the index.
    double operator[](int str);
    inline vector<double> operator[](char str){};
};
}  // namespace sensor

#endif
