#ifndef _CUSTOM_VECTOR_HPP_
#define _CUSTOM_VECTOR_HPP_

namespace custom_stl {
template <typename T> class Vector {
private:
    // The operation of narrowing or expanding the array
    void resizeArr();

    // Starting the modification of the array depending on its size
    void update();

    // Offset of array data by one to the left by iterator
    void offsetToLeft(T *it);

    // Offset of array data by one to the right by iterator
    void offsetToRight(T *it);

    // Freeing the array memory and zeroing the pointer
    void freeArr();

    // Bring the vector to an empty form
    void toEmpty();

    // Bring the vector to a certain size
    T *moveArr(unsigned int size);

    // Checking the array pointer for 0
    bool checkArrNull();

public:
    // Default Constructor
    Vector();
    // Constructor with array size
    Vector(const unsigned int size);
    // Copy Constructor
    Vector(const Vector &other);

    // Array Size
    unsigned int size();
    // Array capacity
    unsigned int capacity();

    // Changing the size of the array
    void resize(const unsigned int size);

    // Inserting an element by iterator
    void insert(T *it, const T elem);

    // Add an 1 element to the beginning
    void push_front(const T elem);
    // Add an 1 element to the end
    void push_back(const T elem);

    // Place the 1 element at the beginning
    void emplace_front(const T &elem);
    // Place the 1 element at the end
    void emplace_back(const T &elem);

    // Remove 1 element from the beginning
    void pop_front();
    // Remove 1 element from the end
    void pop_back();

    // Delete an element by iterator
    void erase(T *it);
    // Delete 1 item by index
    void erase(unsigned int index);

    // Clear Vector
    void clear();

    // Checking for emptiness
    bool empty();

    // Pointer to the beginning of the array
    T *begin();
    // Pointer to the end of the array
    T *end();

    // Constant pointer to the beginning of the array
    const T *cbegin();
    // Constant pointer to the end of the array
    const T *cend();

    // Overloading the indexing operator
    T &operator[](unsigned int index);

    // Overloading the assignment operator
    Vector<T> &operator=(const Vector<T> &other);

    // Vector Destructor
    ~Vector();

private:
    unsigned int capacity_;
    unsigned int size_;
    T *arr_;
};

} // namespace custom_stl

#include "template/custom_vector.tpp"

#endif // _CUSTOM_VECTOR_HPP_
