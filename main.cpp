#include <iostream>
#include <json/json.h>
#include "fstream"


int main() {
    std::ifstream in_file("/Users/alex/CLionProjects/kursach/ne_50m_admin_0_countries.json");
    Json::Value root;
    Json::Reader reader;

    bool parsingSuccessful = reader.parse(in_file, root);
    if (!parsingSuccessful) {
        std::cout << "Ошибка чтения файла" << std::endl;
    }

    const Json::Value values = root["features"];
    const int sz = int(values.size());
    std::vector<Json::Value> v(sz);
    for (int i = 0; i < sz; ++i)
        v[i] = values[i]["properties"];

    int country_number;
    char answer;
    std::string key;

    std::cout << "\nВведите номер страны (от 1 до " << values.size() << "): \n";
    std::cin >> country_number;
    std::cout << v[country_number - 1]["NAME_EN"] << ' ' << v[country_number - 1]["ISO_A2"] << ' '
              << v[country_number - 1]["ISO_A3"] << std::endl;

    std::cout << "\nВывести информацию о данной стране? (y/n): \n";
    std::cin >> answer;
    if (answer == 'y') {
        std::cout << v[country_number - 1];
    }

    std::cout << "\nНужна сортировка? (y/n): \n";
    std::cin >> answer;
    if (answer == 'y') {
        std::cout << "\nПо какому полю отсортировать?: \n";
        std::cin >> key;
        for (int i = 1; i < sz; ++i) {
            int j = i - 1;
            while (v[j][key] > v[j + 1][key]) {
                swap(v[j], v[j + 1]);
                j--;
            }
        }
    }

    std::cout << "\nВведите номер страны (от 1 до " << values.size() << "): \n";
    std::cin >> country_number;
    std::cout << v[country_number - 1]["NAME_EN"] << ' ' << v[country_number - 1]["ISO_A2"] << ' '
              << v[country_number - 1]["ISO_A3"] << std::endl;

    std::cout << "\nВывести информацию о данной стране? (y/n): \n";
    std::cin >> answer;
    if (answer == 'y') {
        std::cout << v[country_number - 1];
    }

    return 0;
}