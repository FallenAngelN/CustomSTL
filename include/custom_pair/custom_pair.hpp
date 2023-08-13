#ifndef _CUSTOM_PAIR_HPP_
#define _CUSTOM_PAIR_HPP_

namespace custom_stl {
template <typename T1, typename T2> struct Pair {
public:
    T1 first;
    T2 second;

    Pair() {}

    Pair(const Pair &other)
    {
        this->first = other.first;
        this->second = other.second;
    }

    // Exchange of values between two pairs
    void swap(Pair<T1, T2> &other)
    {
        T1 temp_t1 = this->first;
        T2 temp_t2 = this->second;
        this->first = other.first;
        this->second = other.second;
        other.first = temp_t1;
        other.second = temp_t2;
    }

    // Copying values from another pair
    Pair<T1, T2> &operator=(const Pair<T1, T2> &other)
    {
        this->first = other.first;
        this->second = other.second;

        return *this;
    }
};
} // namespace custom_stl

#endif // _CUSTOM_PAIR_HPP_
