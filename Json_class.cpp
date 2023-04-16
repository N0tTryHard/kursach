//
// Created by Господин on 21.03.2023.
//

#include "Json_class.h"

Json_class::Json_class(std::string _filepath) {
    std::ifstream inFile(_filepath);
    if (!inFile.is_open()) std::cout << "Не удалось открыть файл.\n";

    bool parsingSuccessful = reader.parse(inFile, root);
    if (!parsingSuccessful) {
        std::cout << "Ошибка чтения файла" << std::endl;
    }

    inFile.close();

    values = root["features"];
    sz = int(values.size());
    v.resize(sz);
    for (int i = 0; i < sz; ++i)
        v[i] = values[i]["properties"];
}

int Json_class::get_size() {
    return sz;
}

void Json_class::Country_name(int country_number) {
    std::cout << v[country_number - 1]["NAME_EN"] << ' ' << v[country_number - 1]["ISO_A2"] << ' '
              << v[country_number - 1]["ISO_A3"] << std::endl;
}

void Json_class::Country_info(int country_number) {
    std::cout << v[country_number - 1];
}

void Json_class::sort_key(std::string key) {
    for (int i = 1; i < sz; ++i) {
        int j = i - 1;
        while (v[j][key] > v[j + 1][key]) {
            swap(v[j], v[j + 1]);
            j--;
        }
    }
}


void Json_class::save_in_file(std::string _filepath, std::string *arr) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outFile(_filepath);
    if (!outFile.is_open()) std::cout << "Не удалось открыть файл.\n";

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < arr->size() - 2; ++j) {
            writer->write(v[i][arr[j]], &outFile);
        }

    }

    outFile.close();
}




