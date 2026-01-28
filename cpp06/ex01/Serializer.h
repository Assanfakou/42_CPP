#ifndef SERIALIZER
#define SERIALIZER

#include "Data.h"
#include <stdint.h>

class Serializer
{
      public:
        Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        ~Serializer();

        static Data* deserialize(uintptr_t raw);
        static uintptr_t serialize(Data* ptr);
};

#endif
