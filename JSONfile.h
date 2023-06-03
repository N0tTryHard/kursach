//
// Created by Господин on 03.06.2023.
//

#ifndef KURSACH_JSONFILE_H
#define KURSACH_JSONFILE_H


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <json/json.h>

using namespace std;

class JsonHandler {
private:
    Json::Value root;

public:
    void loadFromFile(string filename);

    void sortData(string field);

    void countryName(int num);

    void countryInfo(int num);

    void selectFields(Json::Value &fields);

    void saveToFile(string filename);
};

#endif //KURSACH_JSONFILE_H