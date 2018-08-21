#ifndef _DATA_H
#define _DATA_H

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "3rd_party_include/json.hpp"

using namespace std;

using json = nlohmann::json;
namespace data {
/** This is a wrapper class for json library by nlohmann. This class is used to
 * extract relevant data from the json file.
 */
class ReadJson {
    /// contains the parsed text from the json file.
    json parsed_text;
    /// name of the json file
    string file_name;
    /// container to store a 2d vector
    vector<vector<double>> data_2D;
    /// container to store a 1d vector
    vector<double> data_1D;
    /// size of the container
    int size;

   public:
    ReadJson() = delete;
    /// Constructor for the ReadJson class.
    explicit ReadJson(string name);
    /// Destructor for the ReadJson class.
    ~ReadJson();
    /// Extract the 1d vector from the json file which matches with the key.
    vector<double> get_data_vector_1D(string key);
    /// Extract the 2d vector from the json file which matches with the keys.
    const vector<vector<double>> get_data_vector_2D(string key1, string key2,
                                                    string key3);
    /// Extract Accelerometer data from the json file.
    const vector<vector<double>> get_accelerometer_data();
    /// Extract Gyroscope data from the json file.
    const vector<vector<double>> get_gyroscope_data();
    /// Extract Magnetometer data from the json file.
    const vector<vector<double>> get_magnetometer_data();

    /// Extract Light data from the json file.
    const vector<double> get_light_data();
    /// Extract Sound data from the json file.
    vector<double> get_sound_data();
};
}  // namespace data

#endif
