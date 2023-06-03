//
// Created by Господин on 03.06.2023.
//

#include "JSONfile.h"

void JsonHandler::loadFromFile(string filename) {
    ifstream ifs(filename);
    ifs >> root;
    ifs.close();
}

void JsonHandler::sortData(string field) {
    Json::Value array = root["features"];
    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i]["properties"][field] > array[j]["properties"][field]) {
                Json::Value temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    root["features"] = array;
}

void JsonHandler::countryName(int num) {
    std::cout << root["features"][num - 1]["properties"]["NAME"] << ' '
              << root["features"][num - 1]["properties"]["ISO_A2"] << ' '
              << root["features"][num - 1]["properties"]["ISO_A3"] << std::endl;
}

void JsonHandler::countryInfo(int num) {
    std::cout << root["features"][num - 1]["properties"] << std::endl;
}

void JsonHandler::selectFields(Json::Value &fields) {
    Json::Value array = root["features"];
    for (int i = 0; i < array.size(); i++) {
        Json::Value properties = array[i]["properties"];
        Json::Value newProperties;
        for (auto field: fields) {
            newProperties[field.asString()] = properties[field.asString()];
        }
        array[i]["properties"] = newProperties;
    }
    root["features"] = array;
}

void JsonHandler::saveToFile(string filename) {
    ofstream ofs(filename);
    ofs << root;
    ofs.close();
}



