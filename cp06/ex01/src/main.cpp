#include <iostream>
#include "../includes/Serializer.hpp"

int main() {
    Data originalData = {42, "Example Data", 3.14f};

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
