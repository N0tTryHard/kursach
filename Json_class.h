//
// Created by Господин on 21.03.2023.
//

#ifndef KURSACH_JSON_CLASS_H
#define KURSACH_JSON_CLASS_H

#include <iostream>
#include "fstream"
#include <json/json.h>


class Json_class {
private:
    Json::Value root;
    Json::Reader reader;
    Json::Value values;
    std::vector<Json::Value> v;
    int sz;
public:

    Json_class(std::string _filepath);

    int get_size();

    void Country_name(int country_number);

    void Country_info(int country_number);

    void sort_key(std::string key);

    void save_in_file(std::string _filepath,  std::string *arr);
};


#endif //KURSACH_JSON_CLASS_H
