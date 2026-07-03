#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<typename T>
class DynamicArray {
private:
    int size;
    int capacity;
    T* arr;

public:
    // Constructors 
    DynamicArray();
    DynamicArray(int capacity);

    // Rule of Three
    //Deconstructor
    ~DynamicArray();
    //copy constructor
    DynamicArray(const DynamicArray<T>& other);
    //assignment operator
    DynamicArray<T>& operator=(const DynamicArray<T>& other);

    // Getters
    int getSize() const;
    int getCapacity() const;

    // Internal helpers
    void regrow();
    void shrink();

    // Main operations
    void append(const T& data);
    void insert(int index, const T& data);
    void remove(int index);

    // Access
    const T& get(int index) const;
};

#include "DynamicArray.tpp"

#endif