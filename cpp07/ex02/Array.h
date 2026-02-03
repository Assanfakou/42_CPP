#ifndef ARRAY
#define ARRAY

#include <iostream>

template <typename T>

class Array
{
      private:
        T *array;
        unsigned int size;
      public:
        Array();
        Array(unsigned int _size);
        Array(const Array &other);
        Array &operator=(const Array &other);
        const T& operator[](unsigned int index) const;
        T&operator[](unsigned int index);
        ~Array();

        unsigned int getSize() const;
};

template <typename T>
Array<T>::Array() : array(NULL), size(0) {}

template <typename T>
Array<T>::Array(unsigned int _size)
{
        if (_size > 0)
        {
                array = new T[_size];
                size = _size;
        }
        else
                throw std::out_of_range("this is invalide size");
}

template <typename T>
Array<T> ::Array(const Array &other)
{
        array = new T[other.size];
        size = other.size;
        for (unsigned int i = 0; i < size; i++)
        {
                array[i] = other.array[i];
        }
}

template <typename T>

Array<T>& Array<T>::operator=(const Array<T> &other)
{
        if (this != &other)
        {
                delete []array;
                size = other.size;
                array = NULL;
                if (size > 0)
                {
                        array = new T[size];
                        for (unsigned int i = 0; i < size; i++)
                        {
                                array[i] = other.array[i];
                        }
                }
        }
        return (*this);
}

template <typename T>

const T& Array<T>::operator[](unsigned int index) const
{
        if (index >= size)
                throw std::out_of_range("Array index out of bounds");
        return array[index];
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
        if (index >= size)
                throw std::out_of_range("Array index out of bounds");
        return array[index];
}
template <typename T>

unsigned int Array<T>::getSize() const
{
    return size;
}

template <typename T>

Array<T>::~Array()
{
        delete []array;
}
#endif
