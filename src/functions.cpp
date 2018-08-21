#include <cmath>
#include <vector>
#include "include/accelerometer.h"
#include "include/gyroscope.h"

using namespace std;
vector<vector<double>> roll_pitch_yaw(sensor::Accelerometer acc, sensor::Gyroscope gyro){
    vector<vector<double>> result(acc['x'].size());
    
    
    for(int i = 0; i < acc['x'].size(); i++) {
        result[i]  = vector<double>(3);
        auto ax = acc['x'][i];
        auto ay = acc['y'][i];
        auto az = acc['z'][i];
        auto mx = gyro['x'][i];
        auto my = gyro['y'][i];
        auto mz = gyro['z'][i];
        
        result[i][0] = atan2(ay, (sqrt( (ax * ax) + (az * az)))) * 57.3; // pitch
        result[i][1] = atan2(ay, (sqrt( (ax * ax) + (az * az)))) * 57.3; // roll

        auto Yh = (my * cos(result[i][1])) - (mz * sin(result[i][1]));
        auto Xh = (mx * cos(result[i][0])) + (my * sin(result[i][1]) * sin(result[i][0])) + (mz * cos(result[i][1]) * sin(result[i][0]));

        result[i][2] =  atan2(Yh, Xh) * 57.3; // yaw
}    
        return result;
}





