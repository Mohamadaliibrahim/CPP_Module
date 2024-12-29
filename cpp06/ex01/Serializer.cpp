#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(const Serializer &)
{

}

Serializer &Serializer::operator=(const Serializer &)
{
    return (*this);
}

//converts from string(pointer) to unsigned int

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

//converts from unsigned int to string(pointer)..

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}