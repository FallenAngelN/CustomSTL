#ifndef _CUSTOM_VECTOR_HPP_
#define _CUSTOM_VECTOR_HPP_

#include <initializer_list>

namespace custom_stl {
template <typename T> class Vector {

    using uint32_t = unsigned int;
    using iterator = T *;
    using const_iterator = const T *;

private:
    // The operation of narrowing or expanding the array
    void resizeArr()
    {
        T *arr_new = moveArr(this->size_);
        freeArr();
        this->arr_ = arr_new;
    }

    // Starting the modification of the array depending on its size
    void update()
    {
        if (this->size_ == 0) {
            toEmpty();
        }
        else if (this->size_ <= this->capacity_ / 4 || this->size_ >= this->capacity_) {
            resizeArr();
        }
    }

    // Offset of array data by one to the left by iterator
    void offsetToLeft(iterator it)
    {
        iterator temp = this->end() - 1;
        while (temp != it) {
            *(++it - 1) = *(it);
        }
    }

    // Offset of array data by one to the right by iterator
    void offsetToRight(iterator it)
    {
        iterator temp = this->end();
        while (it != temp) {
            *(--temp) = *(temp - 1);
        }
    }

    // Freeing the array memory and zeroing the pointer
    void freeArr()
    {
        if (!checkArrNull()) {
            delete[] this->arr_;
            this->arr_ = nullptr;
        }
    }

    // Bring the vector to an empty form
    void toEmpty()
    {
        freeArr();
        this->size_ = 0;
        this->capacity_ = 0;
    }

    // Bring the vector to a certain size
    T *moveArr(uint32_t size)
    {
        this->capacity_ = size * 2;
        this->size_ = size;
        T *arr_new = new T[this->capacity_];

        if (!checkArrNull()) {
            for (uint32_t i = 0; i < this->size_; ++i) {
                arr_new[i] = this->arr_[i];
            }
        }

        return arr_new;
    }

    // Checking the array pointer for 0
    bool checkArrNull() { return this->arr_ == nullptr; }

public:
    // Default Constructor
    Vector() : capacity_(0), size_(0), arr_(nullptr) {}

    // Constructor with array size
    Vector(const uint32_t size) : capacity_(size * 2), size_(size)
    {
        this->arr_ = this->size_ == 0 ? nullptr : new T[this->capacity_];
    }

    // Constructor with list-initializer
    Vector(std::initializer_list<T> list) : capacity_(list.size() * 2), size_(list.size())
    {
        this->arr_ = this->size_ == 0 ? nullptr : new T[this->capacity_];
        if (!checkArrNull()) {
            auto begin_ = list.begin();
            for (uint32_t i = 0; i < this->size_; ++i) {
                this->arr_[i] = begin_[i];
            }
        }
    }

    // Copy Constructor
    Vector(const Vector &other) : capacity_(other.capacity_), size_(other.size_)
    {
        this->arr_ = this->capacity_ == 0 ? nullptr : new T[this->capacity_];
        if (!checkArrNull()) {
            for (uint32_t i = 0; i < this->size_; ++i) {
                this->arr_[i] = other.arr_[i];
            }
        }
    }

    // Array Size
    uint32_t size() { return this->size_; }

    // Array capacity
    uint32_t capacity() { return this->capacity_; }

    // Changing the size of the array
    void resize(const uint32_t size)
    {
        if (size == 0) {
            toEmpty();
            return;
        }

        uint32_t temp = (size < this->size_ ? size : this->size_);

        if (checkArrNull()) {
            this->capacity_ = size * 2;
            this->size_ = size;
            this->arr_ = new T[this->capacity_];
            return;
        }

        T *arr_new = moveArr(temp);
        freeArr();
        this->arr_ = arr_new;
    }

    // Inserting an element by iterator
    void insert(iterator it, const T elem)
    {
        ++this->size_;
        update();

        T *temp = it;
        offsetToRight(temp);
        *it = elem;
    }

    // Add an 1 element to the beginning
    void push_front(const T elem)
    {
        ++this->size_;
        update();

        offsetToRight(this->begin());
        *begin() = elem;
    }

    // Add an 1 element to the end
    void push_back(const T elem)
    {
        ++this->size_;
        update();

        *(end() - 1) = elem;
    }

    // Place the 1 element at the beginning
    void emplace_front(const T &elem)
    {
        ++this->size_;
        update();

        offsetToRight(begin());
        *begin() = elem;
    }

    // Place the 1 element at the end
    void emplace_back(const T &elem)
    {
        ++this->size_;
        update();

        *(end() - 1) = elem;
    }

    // Remove 1 element from the beginning
    void pop_front()
    {
        offsetToLeft(begin());

        --this->size_;
        update();
    }

    // Remove 1 element from the end
    void pop_back()
    {
        --this->size_;
        update();
    }

    // Delete an element by iterator
    void erase(iterator it)
    {
        offsetToLeft(it);

        --this->size_;
        update();
    }

    // Delete 1 item by index
    void erase(uint32_t index)
    {
        offsetToLeft(this->begin() + index);

        --this->size_;
        update();
    }

    // Clear Vector
    void clear()
    {
        freeArr();
        this->capacity_ = 0;
        this->size_ = 0;
    }

    // Checking for emptiness
    bool empty() { return checkArrNull(); }

    // Pointer to the beginning of the array
    iterator begin() { return this->arr_; }

    // Pointer to the end of the array
    iterator end() { return this->arr_ + this->size_; }

    // Constant pointer to the beginning of the array
    const_iterator cbegin() { return this->arr_; }

    // Constant pointer to the end of the array
    const_iterator cend() { return this->arr_ + this->size_; }

    // Overloading the indexing operator
    T &operator[](uint32_t index) { return *(this->arr_ + index); }

    // Overloading the assignment operator
    Vector<T> &operator=(const Vector<T> &other)
    {
        if (other.size_ == 0) {
            toEmpty();
        }
        else {
            this->capacity_ = other.capacity_;
            this->size_ = other.size_;
            freeArr();
            if (other.arr_ != nullptr) {
                this->arr_ = new T[this->capacity_];
                for (uint32_t i = 0; i < this->size_; ++i) {
                    this->arr_[i] = other.arr_[i];
                }
            }
        }
        return *this;
    }

    // Vector Destructor
    ~Vector() { freeArr(); }

private:
    uint32_t capacity_;
    uint32_t size_;
    T *arr_;
};
} // namespace custom_stl

#endif // _CUSTOM_VECTOR_HPP_
