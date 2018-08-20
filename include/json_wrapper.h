#ifndef _DATA_H
#define _DATA_H

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "json.hpp"

using namespace std;

using json = nlohmann::json;
namespace data {
class ReadJson {
    json parsed_text;
    string file_name;
    vector<vector<double>> data_3D;
    vector<double> data_1D;
    int size;

   public:
    ReadJson() = delete;
    ReadJson(string name);
    ~ReadJson();
    vector<double> get_data_vector_1D(string key);
    const vector<vector<double>> get_data_vector_3D(string key1, string key2,
                                                    string key3);
    const vector<vector<double>> get_accelerometer_data();
    const vector<vector<double>> get_gyroscope_data();
    const vector<vector<double>> get_magnetometer_data();

    const vector<double> get_light_data();
    vector<double> get_sound_data();
};
}  // namespace data

#endif
