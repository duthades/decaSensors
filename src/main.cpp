#include <iostream>
#include <vector>
#include "include/accelerometer.h"
#include "include/imu.h"
#include "include/sensor.h"
using json = nlohmann::json;

int main() {
    data::ReadJson data("data/data.json");

    sensor::Sensor* sen1;
    sensor::Sensor* sen2;

    sen1 = new sensor::Accelerometer(data.get_accelerometer_data());
    std::cout << sen1->get_x_data().size() << "\n";
    return 0;
}
