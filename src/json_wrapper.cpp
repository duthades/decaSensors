#include <include/json_wrapper.h>

namespace data {
data::ReadJson::ReadJson(string name) : file_name(name) {
    std::ifstream fin(name);
    parsed_text = json::parse(fin);
    size = parsed_text.size();
}
data::ReadJson::~ReadJson() {
    data_2D.clear();
    data_1D.clear();
}
vector<double> data::ReadJson::get_data_vector_1D(string key) {
    data_1D.resize(size);
    auto iter = parsed_text.begin();
    int i = 0;
    for (iter; iter != parsed_text.end(); ++iter, i++) {
        data_1D[i] = (*iter)[key];  // value at acc_x in double
    }
    return data_1D;
}
const vector<vector<double>> data::ReadJson::get_data_vector_2D(string key1,
                                                                string key2,
                                                                string key3) {
    data_2D.resize(size);
    auto iter = parsed_text.begin();
    int i = 0;
    for (iter; iter != parsed_text.end(); ++iter, i++) {
        data_2D[i] = vector<double>(3);
        data_2D[i][0] = (*iter)[key1];
        data_2D[i][1] = (*iter)[key2];
        data_2D[i][2] = (*iter)[key3];
    }
    return data_2D;
}
const vector<vector<double>> data::ReadJson::get_accelerometer_data() {
    return get_data_vector_2D("acc_x", "acc_y", "acc_z");
}
const vector<vector<double>> data::ReadJson::get_gyroscope_data() {
    return get_data_vector_2D("gyro_x", "gyro_y", "gyro_z");
}
const vector<vector<double>> data::ReadJson::get_magnetometer_data() {
    return get_data_vector_2D("m_field_x", "m_field_y", "m_field_z");
}

const vector<double> data::ReadJson::get_light_data() {
    return get_data_vector_1D("light");
}

vector<double> data::ReadJson::get_sound_data() {
    return get_data_vector_1D("sound");
}

}  // namespace data
