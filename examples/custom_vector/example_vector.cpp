#include "../../include/custom_vector/custom_vector.hpp"
#include <iostream>

using namespace std;
using namespace custom_stl;

template <typename T> void showArrVector(Vector<T> &v);

template <typename T> void showDataVector(Vector<T> &v);

template <typename T> Vector<T> checkDefaultConstructor();

template <typename T> void checkPushBack(Vector<T> &v);

template <typename T> void checkPushFront(Vector<T> &v);

template <typename T> void checkInsert(Vector<T> &v);

template <typename T> void checkClear(Vector<T> &v);

template <typename T> void checkEmpty(Vector<T> &v);

template <typename T> void checkPopBack(Vector<T> &v);

template <typename T> void checkPopFront(Vector<T> &v);

template <typename T> void checkEmplaceBack(Vector<T> &v);

template <typename T> void checkEmplaceFront(Vector<T> &v);

template <typename T> void checkEraseIterator(Vector<T> &v);

template <typename T> void checkEraseIndex(Vector<T> &v);

template <typename T> void checkResize(Vector<T> &v);

template <typename T> void checkCapacity(Vector<T> &v);

template <typename T> void checkSize(Vector<T> &v);

template <typename T> void checkConstructorWithSize();

template <typename T> void checkConstructorCopy(Vector<T> &v);

template <typename T> void clearVector(Vector<T> &v);

template <typename T> void checkOperatorIndex(Vector<T> &v);

template <typename T> void checkOperatorAssignment(Vector<T> &v);

template <typename T> void checkInitializerList();

int main()
{
    Vector<int> v = checkDefaultConstructor<int>();

    checkPushBack(v);

    checkPushFront(v);

    checkInsert(v);

    checkEmpty(v);

    checkPopBack(v);

    checkPopFront(v);

    checkEmplaceBack(v);

    checkEmplaceFront(v);

    checkEraseIterator(v);

    checkEraseIndex(v);

    checkResize(v);

    checkCapacity(v);

    checkSize(v);

    checkConstructorWithSize<int>();

    checkConstructorCopy(v);

    checkOperatorIndex(v);

    checkOperatorAssignment(v);

    checkInitializerList<int>();
}

template <typename T> void showArrVector(Vector<T> &v)
{
    T *it = v.begin();
    while (it != v.end()) {
        cout << *(it++) << ' ';
    }
}

template <typename T> void showDataVector(Vector<T> &v)
{
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;
    cout << "Address arr: " << v.begin() << endl;
    cout << "Arr data: ";
    showArrVector(v);
    cout << endl << endl;
}

template <typename T> Vector<T> checkDefaultConstructor()
{
    cout << "Check Default Constructor" << endl;

    Vector<T> v;
    showDataVector(v);

    return v;
}

template <typename T> void checkPushBack(Vector<T> &v)
{
    cout << "Check push_back" << endl;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(25);
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkPushFront(Vector<T> &v)
{
    cout << "Check push_front" << endl;

    v.push_front(5);
    v.push_front(10);
    v.push_front(15);
    v.push_front(20);
    v.push_front(25);
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkInsert(Vector<T> &v)
{
    cout << "Check insert" << endl;

    v.push_back(10);
    v.push_back(20);
    v.insert(v.begin() + 1, 15);
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkClear(Vector<T> &v)
{
    cout << "Clear" << endl;

    v.clear();
    showDataVector(v);
}

template <typename T> void checkEmpty(Vector<T> &v)
{
    cout << "Check empty" << endl;

    cout << (v.empty() ? "Empty" : "No empty") << endl;
    v.push_back(15);

    cout << "Check empty after push" << endl;
    cout << (v.empty() ? "Empty" : "No empty") << endl;

    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkPopBack(Vector<T> &v)
{
    cout << "Check pop_back" << endl;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.pop_back();
    v.pop_back();
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkPopFront(Vector<T> &v)
{
    cout << "Check pop_front" << endl;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.pop_front();
    v.pop_front();
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkEmplaceBack(Vector<T> &v)
{
    cout << "Check emplace_back" << endl;

    v.emplace_back(5);
    v.emplace_back(10);
    v.emplace_back(15);
    v.emplace_back(20);
    v.emplace_back(25);
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkEmplaceFront(Vector<T> &v)
{
    cout << "Check emplace_front" << endl;

    v.emplace_front(5);
    v.emplace_front(10);
    v.emplace_front(15);
    v.emplace_front(20);
    v.emplace_front(25);
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkEraseIterator(Vector<T> &v)
{
    cout << "Check erase iterator" << endl;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(25);

    showDataVector(v);
    v.erase(v.begin() + 2);
    v.erase(v.begin() + 2);
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkEraseIndex(Vector<T> &v)
{
    cout << "Check erase index" << endl;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(25);

    showDataVector(v);
    v.erase(2);
    v.erase(2);
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkResize(Vector<T> &v)
{
    cout << "Check resize" << endl;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(25);
    v.push_back(30);
    v.push_back(35);
    v.push_back(40);
    showDataVector(v);

    v.resize(2);
    showDataVector(v);

    v.resize(0);
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkCapacity(Vector<T> &v)
{
    cout << "Check capacity" << endl;

    v.push_back(5);
    cout << endl << "Add 1 elem" << endl;
    cout << "Capacity: " << v.capacity() << endl << endl;

    v.push_back(10);
    v.push_back(15);
    cout << endl << "Add 3 elem" << endl;
    cout << "Capacity: " << v.capacity() << endl << endl;

    v.push_back(20);
    v.push_back(25);
    v.push_back(30);
    cout << endl << "Add 6 elem" << endl;
    cout << "Capacity: " << v.capacity() << endl << endl;

    v.push_back(35);
    v.push_back(40);
    cout << endl << "Add 8 elem" << endl;
    cout << "Capacity: " << v.capacity() << endl << endl;

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    cout << endl << "Pop 4 elem" << endl;
    cout << "Capacity: " << v.capacity() << endl << endl;

    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkSize(Vector<T> &v)
{
    cout << "Check size" << endl;

    v.push_back(5);
    cout << endl << "Add 1 elem" << endl;
    cout << "Size: " << v.size() << endl << endl;

    v.push_back(10);
    v.push_back(15);
    cout << endl << "Add 3 elem" << endl;
    cout << "Size: " << v.size() << endl << endl;

    v.push_back(20);
    v.push_back(25);
    v.push_back(30);
    cout << endl << "Add 6 elem" << endl;
    cout << "Size: " << v.size() << endl << endl;

    v.push_back(35);
    v.push_back(40);
    cout << endl << "Add 8 elem" << endl;
    cout << "Size: " << v.size() << endl << endl;

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    cout << endl << "Pop 4 elem" << endl;
    cout << "Size: " << v.size() << endl << endl;

    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkConstructorWithSize()
{
    cout << "Check cunstructor with size" << endl;

    cout << endl << "Create vector with size: 10" << endl;
    Vector<int> v_10(10);
    showDataVector(v_10);

    cout << endl << "Create vector with size: 4" << endl;
    Vector<int> v_4(4);
    showDataVector(v_4);

    cout << endl << "Create vector with size: 0" << endl;
    Vector<int> v_0(0);
    showDataVector(v_0);
}

template <typename T> void checkConstructorCopy(Vector<T> &v)
{
    cout << "Check constructor copy" << endl;

    cout << endl << "Data original empty vector:" << endl;
    showDataVector(v);
    Vector<T> v_copy_empty(v);
    cout << endl << "Data copy: " << endl;
    showDataVector(v_copy_empty);

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(25);
    cout << "Data original non empty vector: " << endl;
    showDataVector(v);
    Vector<T> v_copy_non_empty(v);
    cout << endl << "Data copy: " << endl;
    showDataVector(v_copy_non_empty);

    clearVector(v);
}

template <typename T> void clearVector(Vector<T> &v) { v.clear(); }

template <typename T> void checkOperatorIndex(Vector<T> &v)
{
    cout << "Check operator []" << endl;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(25);
    cout << "First element: " << v[0] << endl;
    cout << "Third element: " << v[2] << endl;
    cout << "Last element: " << v[4] << endl;
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkOperatorAssignment(Vector<T> &v)
{
    cout << "Check operator =" << endl;

    Vector<T> temp_1;
    cout << "Check assignment empty vector" << endl;
    cout << "Empty vector data: " << endl;
    showDataVector(temp_1);
    v = temp_1;
    cout << "Data original vector" << endl;
    showDataVector(v);

    Vector<T> temp_2;
    temp_2.push_back(5);
    temp_2.push_back(10);
    temp_2.push_back(15);
    temp_2.push_back(20);
    temp_2.push_back(25);
    cout << "Check assignment non empty vector" << endl;
    cout << "Non empty vector data:" << endl;
    showDataVector(temp_2);
    v = temp_2;
    cout << "Data original vector:" << endl;
    showDataVector(v);

    clearVector(v);
}

template <typename T> void checkInitializerList(){
    cout << "Check Constructor with initializer_list" << endl;
    Vector<T> v{1,2,3,4,5};
    showDataVector(v);
}