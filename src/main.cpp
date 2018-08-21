#include <iostream>
#include <string>
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
    std::cout << string(5, '\n');
    std::cout << "The distance of office from home is 900 meters."
              << "\n";

    sensor::Accelerometer acc1(data.get_accelerometer_data());
    sensor::Gyroscope gyro1(data.get_gyroscope_data());
    sensor::Magnetometer magneto(data.get_magnetometer_data());
    sensor::Light light1(data.get_light_data());
    sensor::Sound sound1(data.get_sound_data());
    sound1[0];
    std::cout << "The initial accelerometer, gyroscope, magnetometer readings "
                 "are as follows:\n\n";
    std::cout << "\t"
              << "  x\t"
              << "  y\t"
              << "  z\t"
              << "\n";
    std::cout << "Accel:\t" << acc1['x'][0] << ",\t" << acc1['y'][1] << ",\t"
              << acc1['z'][2] << "\tg"
              << "\n";
    std::cout << "Gyro:\t" << gyro1['x'][0] << ",\t" << gyro1['y'][1] << ",\t"
              << gyro1['z'][2] << "\tdps"
              << "\n";
    std::cout << "Mag:\t" << magneto['x'][0] << ",\t" << magneto['y'][1]
              << ",\t" << magneto['z'][2] << "\tuT"
              << "\n\n";
    std::cout << "The calculated roll, pitch and yaw values for the above "
                 "values are as follows:\n";

    auto rpy = roll_pitch_yaw(acc1, magneto);

    std::cout << "Roll: " << rpy[0][0] << "\tpitch: " << rpy[0][1]
              << "\tyaw: " << rpy[0][2] << "\n\n";
    int steps = get_steps(acc1);

    std::cout << "Total Steps taken to reach the office are: " << steps << "\n";
    std::cout << "The stride length is " << 900.0 / steps << " meters\n";
    std::cout << string(5, '\n');
    return 0;
}
