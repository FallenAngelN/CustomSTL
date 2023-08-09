#ifndef _CUSTOM_PAIR_HPP_
#define _CUSTOM_PAIR_HPP_

namespace custom_stl {
template <typename T1, typename T2> struct Pair {
public:
    T1 first;
    T2 second;

    Pair();

    Pair(const Pair &other);

    // Exchange of values between two pairs
    void swap(Pair<T1, T2> &other);

    // Copying values from another pair
    Pair<T1, T2> &operator=(const Pair<T1, T2> &other);
};
} // namespace custom_stl

#include "template/custom_pair.tpp"

#endif // _CUSTOM_PAIR_HPP_
