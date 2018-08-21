#include <cmath>
#include <utility>
#include <vector>
#include "include/accelerometer.h"
#include "include/magnetometer.h"

using namespace std;
vector<vector<double>> roll_pitch_yaw(sensor::Accelerometer& acc,
                                      sensor::Magnetometer& magneto) {
    vector<vector<double>> result(acc['x'].size());

    for (int i = 0; i < acc['x'].size(); ++i) {
        result[i] = vector<double>(3);
        auto ax = acc['x'][i];
        auto ay = acc['y'][i];
        auto az = acc['z'][i];
        auto mx = magneto['x'][i];
        auto my = magneto['y'][i];
        auto mz = magneto['z'][i];

        result[i][1] =
            atan2(ay, (sqrt((ax * ax) + (az * az)))) * 57.3;  // pitch
        result[i][0] = atan2(-1 * ax, (sqrt((ay * ay) + (az * az)))) * 57.3;  // roll

        auto Yh = (my * cos(result[i][1])) - (mz * sin(result[i][1]));
        auto Xh = (mx * cos(result[i][0])) +
                  (my * sin(result[i][1]) * sin(result[i][0])) +
                  (mz * cos(result[i][1]) * sin(result[i][0]));

        result[i][2] = atan2(Yh, Xh) * 57.3;  // yaw
    }
    return std::move(result);
}

int get_steps(sensor::Accelerometer& acc) {
    int peaks = 0;
    vector<double> resultant(acc['x'].size());
    int i = 0;
    for (i; i < acc['x'].size(); i++) {
        resultant[i] =
            sqrt((acc['x'][i] * acc['x'][i]) + (acc['y'][i] * acc['y'][i]) +
                 (acc['z'][i] * acc['z'][i]));
    }

    for (int j = 1; j < resultant.size() - 1; j++) {
        if ((resultant[j - 1] < resultant[j]) &&
            (resultant[j] > resultant[j + 1]))
            peaks++;
    }
    for (int j = 1; j < resultant.size() - 1; j++) {
        if ((-1 * resultant[j - 1] < -1 * resultant[j]) &&
            (-1 * resultant[j] > -1 * resultant[j + 1]))
            peaks++;
    }
    return peaks;
}
