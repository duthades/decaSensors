#include <iostream>
#include <vector>
#include "include/accelerometer.h"
#include "include/gyroscope.h"
#include "include/imu.h"
#include "include/magnetometer.h"
#include "include/sensor.h"

using json = nlohmann::json;

int main() {
    data::ReadJson data("data/data.json");

    sensor::Sensor* sen1;
    sensor::Sensor* sen2;
    sensor::Sensor* sen3;

    sen1 = new sensor::Accelerometer(data.get_accelerometer_data());
    sen2 = new sensor::Gyroscope(data.get_gyroscope_data());
    sen3 = new sensor::Magnetometer(data.get_magnetometer_data());

    std::cout << sen1->get_x_data().size() << "\n";
    delete sen1;
    delete sen2;
    delete sen3;
    return 0;
}
