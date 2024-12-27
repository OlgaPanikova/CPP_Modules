#include "Serializer.hpp"

int main() {
    Data originalData = {42, "Example"};
    Data* originalPtr = &originalData;

    std::cout << "Original Data: " << originalPtr->i << ", " << originalPtr->str << std::endl;

    uintptr_t serializedPtr = Serializer::serialize(originalPtr);

    std::cout << "Serializer Data: " << serializedPtr << std::endl;

    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    std::cout << "Deserialized Data: " << deserializedPtr << std::endl;

    if (originalPtr == deserializedPtr) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Original Data: " << originalPtr->i << ", " << originalPtr->str << std::endl;
    } else {
        std::cout << "Error: Pointers do not match!" << std::endl;
    }

    return 0;
}