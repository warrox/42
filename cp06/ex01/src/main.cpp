#include <iostream>
#include "../includes/Serializer.hpp"

int main() {
    // Create a Data object
    Data originalData = {42, "Example Data", 3.14f};

    // Serialize the Data object's pointer
    uintptr_t serializedData = Serializer::serialize(&originalData);
    std::cout << "Serialized Data: " << serializedData << std::endl;

    // Deserialize back to a Data pointer
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Verify that the deserialized pointer matches the original
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
