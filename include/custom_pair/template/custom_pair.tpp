namespace custom_stl {
template <typename T1, typename T2> inline Pair<T1, T2>::Pair(){}

template <typename T1, typename T2> inline Pair<T1, T2>::Pair(const Pair &other)
{
    this->first = other.first;
    this->second = other.second;
}

template <typename T1, typename T2> inline void Pair<T1, T2>::swap(Pair<T1, T2> &other)
{
    T1 temp_t1 = this->first;
    T2 temp_t2 = this->second;
    this->first = other.first;
    this->second = other.second;
    other.first = temp_t1;
    other.second = temp_t2;
}

template <typename T1, typename T2> inline Pair<T1, T2> &Pair<T1, T2>::operator=(const Pair<T1, T2> &other)
{
    this->first = other.first;
    this->second = other.second;

    return *this;
}
} // namespace custom_stl
