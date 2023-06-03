#include "iostream"
#include "JSONfile.h"


int main() {
    JsonHandler handler;
    std::string filepath;
    std::cout << "Введите путь до файла: \n";
    std::cin >> filepath;

    handler.loadFromFile(filepath);

    int country_number;
    char answer;
    std::string key;

    std::cout << "\nВведите номер страны (от 1 до 242): \n";
    std::cin >> country_number;
    handler.countryName(country_number);

    std::cout << "\nВывести информацию о данной стране? (y/n): \n";
    std::cin >> answer;
    if (answer == 'y') {
        handler.countryInfo(country_number);
    }

    std::cout << "\nНужна сортировка? (y/n): \n";
    std::cin >> answer;
    if (answer == 'y') {
        std::cout << "\nПо какому полю отсортировать?: \n";
        std::cin >> key;
        handler.sortData(key);
    }

    std::cout << "\nВведите номер страны (от 1 до 242): \n";
    std::cin >> country_number;
    handler.countryName(country_number);

    int num;
    std::cout << "Сколько полей нужно записать?: \n";
    std::cin >> num;

    auto *key_arr = new std::string[num];
    std::cout << "Какие поля нужно записать?: \n";
    for (int i = 0; i < num; ++i) {
        std::cin >> key_arr[i];
    }
    Json::Value fields;
    for (int i = 0; i < num; ++i) {
        fields.append(key_arr[i]);
    }
    handler.selectFields(fields);

    std::cout << "В какой файл нужно записать?:\n";
    std::cin >> filepath;
    handler.saveToFile(filepath);

    return 0;
}
