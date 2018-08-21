#include <iostream>
#include <vector>
#include "include/accelerometer.h"
#include "include/functions.h"
#include "include/gyroscope.h"
#include "include/imu.h"
#include "include/light.h"
#include "include/magnetometer.h"
#include "include/sensor.h"
#include "include/sound.h"

using json = nlohmann::json;

int main() {
    data::ReadJson data("data/data.json");

    sensor::Sensor* sen1;
    sensor::Sensor* sen2;
    sensor::Sensor* sen3;
    sensor::Sensor* sen4;
    sensor::Sensor* sen5;

    sensor::Accelerometer acc1(data.get_accelerometer_data());
    sensor::Gyroscope gyro1(data.get_gyroscope_data());
    sensor::Magnetometer magneto(data.get_magnetometer_data());

    sen1 = new sensor::Accelerometer(data.get_accelerometer_data());
    sen2 = new sensor::Gyroscope(data.get_gyroscope_data());
    sen3 = new sensor::Magnetometer(data.get_magnetometer_data());
    sen4 = new sensor::Light(data.get_light_data());
    sen5 = new sensor::Sound(data.get_sound_data());

    std::cout << (*sen1)['x'][0] << "\n";
    std::cout << (*sen2)['y'][0] << "\n";
    std::cout << (*sen3)['z'][0] << "\n";
    std::cout << (*sen4)[0] << "\n";
    std::cout << (*sen5)[0] << "\n";

    auto rpy = roll_pitch_yaw(acc1, magneto);

    std::cout << rpy[0][0] << "\n";
    int steps = get_steps(acc1);

    std::cout << "Total Steps: " << steps << "\n";

    delete sen1;
    delete sen2;
    delete sen3;
    delete sen4;
    delete sen5;

    return 0;
}
