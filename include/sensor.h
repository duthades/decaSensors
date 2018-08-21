#ifndef _SENSOR_H
#define _SENSOR_H
#include <vector>

using namespace std;
namespace sensor {
class Sensor {
   public:
    virtual ~Sensor();
    virtual vector<double> get_y_data() = 0;
    virtual vector<double> get_z_data() = 0;
    virtual vector<double> get_x_data() = 0;
    virtual vector<double> get_data() = 0;
    virtual vector<double> operator[](char str) = 0;
    virtual double operator[](int str) = 0;
};
}  // namespace sensor

#endif
