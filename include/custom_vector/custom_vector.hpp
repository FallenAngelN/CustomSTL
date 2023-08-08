#ifndef _CUSTOM_VECTOR_HPP_
#define _CUSTOM_VECTOR_HPP_

namespace custom_stl {
template <typename T> class Vector {
private:
    void resizeArr();
    void update();

    void offsetToLeft(T *it);

    void offsetToRight(T *it);

    void freeArr();

    void toEmpty();

    T *moveArr(unsigned int size);

    bool checkArrNull();

public:
    Vector();
    Vector(const unsigned int size);
    Vector(const Vector &other);

    unsigned int size();
    unsigned int capacity();

    void resize(const unsigned int size);

    void insert(T *it, const T elem);

    void push_front(const T elem);
    void push_back(const T elem);

    void emplace_front(const T &elem);
    void emplace_back(const T &elem);

    void pop_front();
    void pop_back();

    void erase(T *it);

    void clear();

    bool empty();

    T *begin();
    T *end();

    const T *cbegin();
    const T *cend();

    T& operator[](unsigned int index);

    ~Vector();

private:
    unsigned int size_;
    unsigned int capacity_;
    T *arr_;
};
} // namespace custom_stl

#include "template/custom_vector.tpp"

#endif // _CUSTOM_VECTOR_HPP_
