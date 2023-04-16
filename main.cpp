#include <iostream>
#include "Json_class.h"


int main() {
    std::string filepath;
    std::cout << "Введите путь до файла: \n";
    std::cin >> filepath;

    Json_class OBJ1(filepath);

    int country_number;
    char answer;
    std::string key;

    std::cout << "\nВведите номер страны (от 1 до " << OBJ1.get_size() << "): \n";
    std::cin >> country_number;
    OBJ1.Country_name(country_number);

    std::cout << "\nВывести информацию о данной стране? (y/n): \n";
    std::cin >> answer;
    if (answer == 'y') {
        OBJ1.Country_info(country_number);
    }

    std::cout << "\nНужна сортировка? (y/n): \n";
    std::cin >> answer;
    if (answer == 'y') {
        std::cout << "\nПо какому полю отсортировать?: \n";
        std::cin >> key;
        OBJ1.sort_key(key);
    }

    std::cout << "\nВведите номер страны (от 1 до 242): \n";
    std::cin >> country_number;
    OBJ1.Country_name(country_number);

    int num;
    std::cout << "Сколько полей нужно записать?: \n";
    std::cin >> num;

    auto *key_arr = new std::string[num];
    std::cout << "Какие поля нужно записать?: \n";
    for (int i = 0; i < num; ++i) {
        std::cin >> key_arr[i];
    }

    /*std::cout << "В какой файл нужно записать?:\n";
    std::cin >> filepath;
    OBJ1.save_in_file(filepath);*/

    return 0;
}