#include "Serializer.h"
#include "Data.h"

int main()
{
    Data data;
    data.key = 8008;
    data.letter = "Dear friend";
   char c = (int)'a';
    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* newPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Deserialized pointer: " << newPtr << std::endl;

    if (originalPtr == newPtr)
        std::cout << "Success: pointers are equal" << std::endl;
    else
        std::cout << "Error: pointers are NOT equal" << std::endl;

    return 0;
}
