#include "../../include/custom_pair/custom_pair.hpp"
#include <iostream>

using namespace custom_stl;
using namespace std;

template <typename T1, typename T2> Pair<T1, T2> checkDefaultConstructor();

template <typename T1, typename T2> void checkConstructorCopy(Pair<T1, T2> &p);

template <typename T1, typename T2> void checkParams(Pair<T1, T2> &p);

template <typename T1, typename T2> void checkSwap(Pair<T1, T2> &p);

template <typename T1, typename T2> void showDataPair(Pair<T1, T2> &p);

int main()
{
    Pair<int, char> p = checkDefaultConstructor<int, char>();

    checkConstructorCopy(p);

    checkParams(p);

    checkSwap(p);
}

template <typename T1, typename T2> Pair<T1, T2> checkDefaultConstructor()
{
    cout << "Check Default Constructor" << endl;
    Pair<T1, T2> p;
    showDataPair(p);
    return p;
}

template <typename T1, typename T2> void checkConstructorCopy(Pair<T1, T2> &p) {
    cout << "Check Copy Constructor: " << endl;
    
    cout << "Data original: " << endl;
    p.first = 100;
    p.second = 'Z';
    showDataPair(p);

    Pair<T1, T2> temp(p);
    cout << "Data copy pair: " << endl;
    showDataPair(temp);
}

template <typename T1, typename T2> void checkParams(Pair<T1, T2> &p)
{
    cout << "Check assignment parameters" << endl;

    cout << "Original data:" << endl;
    showDataPair(p);

    p.first = 20;
    p.second = 'c';

    cout << "Change data:" << endl;
    showDataPair(p);
}

template <typename T1, typename T2> void checkSwap(Pair<T1, T2> &p)
{
    cout << "Check swap" << endl;

    cout << "Original data:" << endl;
    showDataPair(p);

    cout << "Data temp pair:" << endl;
    Pair<T1, T2> temp;
    temp.first = 5;
    temp.second = 'Z';
    showDataPair(temp);

    cout << "Data after swap: " << endl;
    p.swap(temp);

    cout << "Data original: " << endl;
    showDataPair(p);

    cout << "Data temp pair: " << endl;
    showDataPair(temp);
}

template <typename T1, typename T2> void showDataPair(Pair<T1, T2> &p)
{
    cout << endl << "Data: "  << &p << endl;
    cout << "First: " << p.first << endl;
    cout << "Second: " << p.second << endl;
    cout << endl;
}
