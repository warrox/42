
#include <iostream>
#include <string>
#include "../includes/Serializer.hpp"

int main() {
    Data originalData;

    std::cout << "Enter ID (integer): ";
    std::cin >> originalData.id;

    std::cin.ignore();
    std::cout << "Enter Name (string): ";
    std::getline(std::cin, originalData.name);

    std::cout << "Enter Value (float): ";
    std::cin >> originalData.value;

    uintptr_t serializedData = Serializer::serialize(&originalData);
    std::cout << "Serialized Data: " << serializedData << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedData);

    if (deserializedData == &originalData) {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Deserialized Data -> ID: " << deserializedData->id
                  << ", Name: " << deserializedData->name
                  << ", Value: " << deserializedData->value << std::endl;
    } else {
        std::cerr << "Deserialization failed!" << std::endl;
    }

    return 0;
}
