#include "Serializer.h"

int main()
{
    Data data;
    data.key = 8008;
    data.letter = "Dear friend";
    Data* originalPtr = &data;

    uintptr_t number = Serializer::serialize(originalPtr);
    Data* newptr = Serializer::deserialize(number);

    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Deserialized pointer: " << newptr << std::endl;

    if (originalPtr == newptr)
        std::cout << "Success: pointers are equal" << std::endl;
    else
        std::cout << "Error: pointers are NOT equal" << std::endl;
}
