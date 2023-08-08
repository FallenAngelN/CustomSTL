namespace custom_stl {
template <typename T> inline void Vector<T>::resizeArr()
{
    T *arr_new = moveArr(this->size_);
    if(!checkArrNull()){
        freeArr();
    }
    this->arr_ = arr_new;
}

template <typename T> inline void Vector<T>::update()
{
    if (this->size_ == 0) {
        toEmpty();
    }
    else if (this->size_ <= this->capacity_ / 4 || this->size_ >= this->capacity_){
        resizeArr();
    }
}

template <typename T> inline void Vector<T>::offsetToLeft(T *it)
{
    T *temp = this->end() - 1;
    while (temp != it) {
        *(++it - 1) = *(it);
    }
}

template <typename T> inline void Vector<T>::offsetToRight(T *it)
{
    T *temp = this->end();
    while (it != temp) {
        *(--temp) = *(temp - 1);
    }
}

template <typename T> inline void Vector<T>::freeArr()
{
    delete[] this->arr_;
    this->arr_ = 0;
}

template <typename T> inline void Vector<T>::toEmpty()
{
    if (!checkArrNull()) {
        freeArr();
    }
    this->size_ = 0;
    this->capacity_ = 0;
}

template <typename T> inline T *Vector<T>::moveArr(const unsigned int size)
{
    this->capacity_ = size * 2;
    T *arr_new = new T[this->capacity_];
    if(!checkArrNull()){
        for (unsigned int i = 0; i < size; ++i) {
            arr_new[i] = this->arr_[i];
        }
    }
    return arr_new;
}

template <typename T> inline bool Vector<T>::checkArrNull() { return this->arr_ == 0; }

template <typename T> inline Vector<T>::Vector()
{
    this->capacity_ = 0;
    this->size_ = 0;
    this->arr_ = 0;
}

template <typename T> inline Vector<T>::Vector(const unsigned int size)
{
    this->capacity_ = size * 2;
    this->size_ = size;
    this->arr_ = size == 0 ? 0 : new T[this->capacity_];
}

template <typename T> inline Vector<T>::Vector(const Vector &other)
{
    this->capacity_ = other.capacity_;
    this->size_ = other.size_;

    if (this->capacity_ == 0) {
        this->arr_ = 0;
    }
    else {
        this->arr_ = new T[this->capacity_];
        for (unsigned int i = 0; i < this->size_; ++i) {
            this->arr_[i] = other.arr_[i];
        }
    }
}

template <typename T> inline unsigned int Vector<T>::size() { return this->size_; }

template <typename T> inline unsigned int Vector<T>::capacity() { return this->capacity_; }

template <typename T> inline void Vector<T>::resize(const unsigned int size)
{
    if(size == 0){
        toEmpty();
    }
    else{
        if (this->arr_ == 0) {
            this->capacity_ = size * 2;
            this->size_ = size;
            this->arr_ = new T[this->capacity_];
        }
        else {
            unsigned int temp = (size < this->size_ ? size : this->size_);
            T *arr_new = moveArr(temp);

            freeArr();
            this->capacity_ = size * 2;
            this->size_ = size;
            this->arr_ = arr_new;
        }
    }

}

template <typename T> inline void Vector<T>::insert(T *it, const T elem)
{
    ++this->size_;
    update();

    T *temp = it;
    offsetToRight(temp);
    *it = elem;
}

template <typename T> inline void Vector<T>::push_front(const T elem)
{
    ++this->size_;
    update();

    offsetToRight(this->begin());
    *begin() = elem;
}

template <typename T> inline void Vector<T>::push_back(const T elem)
{
    ++this->size_;
    update();

    *(end() - 1) = elem;
}

template <typename T> inline void Vector<T>::emplace_front(const T &elem)
{
    ++this->size_;
    update();

    offsetToRight(begin());
    *begin() = elem;
}

template <typename T> inline void Vector<T>::emplace_back(const T &elem)
{
    ++this->size_;
    update();

    *(end() - 1) = elem;
}

template <typename T> inline void Vector<T>::pop_front()
{
    offsetToLeft(begin());

    --this->size_;
    update();
}

template <typename T> inline void Vector<T>::pop_back()
{
    --this->size_;
    update();
}

template <typename T> inline void Vector<T>::erase(T *it)
{
    offsetToLeft(it);

    --this->size_;
    update();
}

template <typename T> inline void Vector<T>::clear()
{
    freeArr();
    this->capacity_ = 0;
    this->size_ = 0;
}

template <typename T> inline bool Vector<T>::empty() { return checkArrNull(); }

template <typename T> inline T *Vector<T>::begin() { return this->arr_; }

template <typename T> inline T *Vector<T>::end() { return this->arr_ + this->size_; }

template <typename T> inline const T *Vector<T>::cbegin() { return this->arr_; }

template <typename T> inline const T *Vector<T>::cend() { return this->arr_ + this->size_; }

template <typename T> inline T &Vector<T>::operator[](unsigned int index) {
    return this->arr_[index];
}

template <typename T> inline Vector<T>::~Vector()
{
    if (!checkArrNull()) {
        freeArr();
    }
}
} // namespace custom_stl
