#include "../../include/custom_single_list/custom_single_list.hpp"
#include <iostream>

using namespace std;
using namespace custom_stl;

template <typename T> void showSingleList(SingleList<T> &list);

template <typename T> void checkConstructorInitializerList();

template <typename T> void checkConstructorBase();

template <typename T> void checkConstructorCopy();

template <typename T> void checkConstructorSingleNode();

template <typename T> void checkPushFrontSingleNode();
template <typename T> void checkPushFrontElem();

template <typename T> void checkPushBaskSingleNode();
template <typename T> void checkPushBackElem();

template <typename T> void checkEmplaceFrontSingleNode();
template <typename T> void checkEmplaceFrontElem();

template <typename T> void checkEmplaceBaskSingleNode();
template <typename T> void checkEmplaceBackElem();

template <typename T> void checkInsertSingleNode();
template <typename T> void checkInsertElem();

template <typename T> void checkPopFront();
template <typename T> void checkPopBack();

template <typename T> void checkErase();
template <typename T> void checkClear();

template <typename T> void checkSize();

template <typename T> void checkEmpty();

template <typename T> void checkBegin();
template <typename T> void checkEnd();

template <typename T> void checkCbegin();
template <typename T> void checkCend();

template <typename T> void checkOperatorAssignment();
template <typename T> void checkOperatorEquality();
template <typename T> void checkOperatorIndex();

int main()
{
    checkConstructorInitializerList<int>();

    checkConstructorBase<int>();

    checkConstructorCopy<int>();

    checkConstructorSingleNode<int>();

    checkPushFrontSingleNode<int>();

    checkPushFrontElem<int>();

    checkPushBaskSingleNode<int>();

    checkPushBackElem<int>();

    checkEmplaceFrontSingleNode<int>();

    checkEmplaceFrontElem<int>();

    checkEmplaceBaskSingleNode<int>();

    checkEmplaceBackElem<int>();

    checkInsertSingleNode<int>();

    checkInsertElem<int>();

    checkPopFront<int>();

    checkPopBack<int>();

    checkErase<int>();

    checkClear<int>();

    checkSize<int>();

    checkEmpty<int>();

    checkBegin<int>();

    checkEnd<int>();

    checkCbegin<int>();

    checkCend<int>();

    checkOperatorAssignment<int>();

    checkOperatorEquality<int>();

    checkOperatorIndex<int>();
}

template <typename T> void showSingleList(SingleList<T> &list)
{
    cout << endl;
    cout << "Data single list." << endl;
    cout << "Size list: " << list.size() << endl;
    cout << "Data list: " << endl;
    SingleNode<T> *elem = list.begin();
    for (unsigned int i = 0, size_ = list.size(); i < size_; ++i) {
        cout << "Value: " << elem->value_ << ". Address: " << elem << ". Address next: " << elem->next_ << endl;
        elem = elem->next_;
    }
    cout << "Address first: " << list.begin() << endl;
    cout << "Address last: " << list.end() << endl;
    cout << endl;
}

template <typename T> void checkConstructorInitializerList()
{
    cout << "Check Constructor with initializer list." << endl;

    cout << "Empty initializer list: " << endl;
    SingleList<T> list{};
    showSingleList(list);

    cout << "Non empty initializer list: " << endl;
    SingleList<T> list_2{1, 2, 3, 4, 5};
    showSingleList(list_2);
}

template <typename T> void checkConstructorBase()
{
    cout << "Check Constructor Base." << endl;
    SingleList<T> list;
    showSingleList(list);
}

template <typename T> void checkConstructorCopy()
{
    cout << "Check Constructor Copy." << endl;

    cout << "Data original: " << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    showSingleList(list);

    cout << "Data Copy: " << endl;
    SingleList<T> list_copy(list);
    showSingleList(list_copy);
}

template <typename T> void checkConstructorSingleNode()
{
    cout << "Check Constructor with SingleNode." << endl;

    cout << "Check SingleNode with next_ == nullptr" << endl;
    SingleNode<T> *node_1 = new SingleNode<T>(5, nullptr);
    SingleList<T> list_1(node_1);
    showSingleList(list_1);

    cout << "Check SingleNode with next_ != nullptr" << endl;
    SingleNode<T> *node_2 = new SingleNode<T>(10, node_1);
    SingleList<T> list_2(node_2);
    showSingleList(list_2);
}

template <typename T> void checkPushFrontSingleNode()
{
    cout << "Check push_front SingleNode." << endl;

    cout << "Push front in empty list: " << endl;
    SingleList<T> list;
    SingleNode<T> *node_1 = new SingleNode<T>(5);
    list.push_front(node_1);
    showSingleList(list);

    cout << "Push front in non empty list with next_ == nullptr: " << endl;
    SingleNode<T> *node_2 = new SingleNode<T>(10);
    list.push_front(node_2);
    showSingleList(list);

    cout << "Push front in non empty list with next_ != nullptr: " << endl;
    SingleNode<T> *node_3 = new SingleNode<T>(15, node_2);
    list.push_front(node_3);
    showSingleList(list);
}

template <typename T> void checkPushFrontElem()
{
    cout << "Check push_front element." << endl;

    cout << "Push front in empty list: " << endl;
    SingleList<T> list;
    list.push_front(5);
    showSingleList(list);

    cout << "Push front in non empty list: " << endl;
    list.push_front(10);
    showSingleList(list);
}

template <typename T> void checkPushBaskSingleNode()
{
    cout << "Check push_back SingleNode." << endl;

    cout << "Push back in empty list: " << endl;
    SingleList<T> list;
    SingleNode<T> *node_1 = new SingleNode<T>(5);
    list.push_back(node_1);
    showSingleList(list);

    cout << "Push back in non empty list with next_ == nullptr: " << endl;
    SingleNode<T> *node_2 = new SingleNode<T>(10);
    list.push_back(node_2);
    showSingleList(list);

    cout << "Push back in non empty list with next_ != nullptr: " << endl;
    SingleNode<T> *node_3 = new SingleNode<T>(15, node_2);
    list.push_back(node_3);
    showSingleList(list);
}

template <typename T> void checkPushBackElem()
{
    cout << "Check push_back element." << endl;

    cout << "Push back in empty list: " << endl;
    SingleList<T> list;
    list.push_back(5);
    showSingleList(list);

    cout << "Push back in non empty list: " << endl;
    list.push_back(10);
    showSingleList(list);
}

template <typename T> void checkEmplaceFrontSingleNode()
{
    cout << "Check emplace_front SingleNode." << endl;

    cout << "Emplace front in empty list: " << endl;
    SingleList<T> list;
    SingleNode<T> *node_1 = new SingleNode<T>(5);
    list.emplace_front(node_1);
    showSingleList(list);

    cout << "Emplace front in non empty list with next_ == nullptr: " << endl;
    SingleNode<T> *node_2 = new SingleNode<T>(10);
    list.emplace_front(node_2);
    showSingleList(list);

    cout << "Emplace front in non empty list with next_ != nullptr: " << endl;
    SingleNode<T> *node_3 = new SingleNode<T>(15, node_2);
    list.emplace_front(node_3);
    showSingleList(list);
}

template <typename T> void checkEmplaceFrontElem()
{
    cout << "Check emplace_front element." << endl;

    cout << "Emplace front in empty list: " << endl;
    SingleList<T> list;
    list.emplace_front(5);
    showSingleList(list);

    cout << "Emplace front in non empty list: " << endl;
    list.emplace_front(10);
    showSingleList(list);
}

template <typename T> void checkEmplaceBaskSingleNode()
{
    cout << "Check emplace_back SingleNode." << endl;

    cout << "Emplace back in empty list: " << endl;
    SingleList<T> list;
    SingleNode<T> *node_1 = new SingleNode<T>(5);
    list.emplace_back(node_1);
    showSingleList(list);

    cout << "Emplace back in non empty list with next_ == nullptr: " << endl;
    SingleNode<T> *node_2 = new SingleNode<T>(10);
    list.emplace_back(node_2);
    showSingleList(list);

    cout << "Emplace back in non empty list with next_ != nullptr: " << endl;
    SingleNode<T> *node_3 = new SingleNode<T>(15, node_2);
    list.emplace_back(node_3);
    showSingleList(list);
}

template <typename T> void checkEmplaceBackElem()
{
    cout << "Check emplace_back element." << endl;

    cout << "Emplace back in empty list: " << endl;
    SingleList<T> list;
    list.emplace_back(5);
    showSingleList(list);

    cout << "Emplace back in non empty list: " << endl;
    list.emplace_back(10);
    showSingleList(list);
}

template <typename T> void checkInsertSingleNode()
{
    cout << "Check insert with SingleNode." << endl;

    cout << "Insert in empty list." << endl;
    SingleList<T> list;
    SingleNode<T> *node_1 = new SingleNode<T>(5, nullptr);
    list.insert(list.begin(), node_1);
    showSingleList(list);

    cout << "Insert in non-empty list with next_ == nullptr." << endl;
    SingleNode<T> *node_2 = new SingleNode<T>(10, nullptr);
    list.insert(list.begin(), node_2);
    showSingleList(list);

    cout << "Insert in empty list with next_ != nullptr." << endl;
    SingleNode<T> *node_3 = new SingleNode<T>(15, node_2);
    list.insert(list.begin(), node_3);
    showSingleList(list);
}

template <typename T> void checkInsertElem()
{
    cout << "Check insert element." << endl;

    cout << "Insert in empty list: " << endl;
    SingleList<T> list;
    list.insert(list.begin(), 5);
    showSingleList(list);

    cout << "Insert in non empty list: " << endl;
    list.insert(list.begin(), 10);
    list.insert(list.begin(), 15);
    showSingleList(list);
}

template <typename T> void checkPopFront()
{
    cout << "Check pop_front." << endl;

    cout << "Data before pop_front." << endl;
    SingleList<int> list{1, 2, 3, 4, 5};
    showSingleList(list);

    cout << "Data after pop_front." << endl;
    list.pop_front();
    showSingleList(list);
}

template <typename T> void checkPopBack()
{
    cout << "Check pop_back." << endl;

    cout << "Data before pop_back." << endl;
    SingleList<int> list{10, 20, 30, 40, 50};
    showSingleList(list);

    cout << "Data after pop_back." << endl;
    list.pop_back();
    list.pop_back();
    list.pop_back();
    showSingleList(list);

    cout << "Data after full pop_back." << endl;
    list.pop_back();
    list.pop_back();
    showSingleList(list);
}

template <typename T> void checkErase()
{
    cout << "Check erase." << endl;

    cout << "Data original: " << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    showSingleList(list);

    cout << "Data after erase begin:" << endl;
    list.erase(list.begin());
    showSingleList(list);

    cout << "Data after erase end:" << endl;
    list.erase(list.end());
    showSingleList(list);

    cout << "Data after erase after first node:" << endl;
    list.erase(list.begin()->next_);
    showSingleList(list);
}

template <typename T> void checkClear()
{
    cout << "Check clear:" << endl;

    cout << "Clear empty list." << endl;
    SingleList<T> list_empty;
    cout << "Data empty list:" << endl;
    showSingleList(list_empty);
    list_empty.clear();
    cout << "Data empty list after clear:" << endl;
    showSingleList(list_empty);

    cout << "Clear non empty list." << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    cout << "Data non empty list:" << endl;
    showSingleList(list);
    list.clear();
    cout << "Data non empty list after clear:" << endl;
    showSingleList(list);
}

template <typename T> void checkSize()
{
    cout << "Check size: " << endl;

    cout << "Check size empty list:" << endl;
    SingleList<T> list_empty;
    cout << "Size empty list: " << list_empty.size() << endl;
    showSingleList(list_empty);

    cout << "Check size non-empty list:" << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    cout << "Size non-empty list: " << list.size() << endl;
    showSingleList(list);
}

template <typename T> void checkEmpty()
{
    cout << "Check empty" << endl;

    cout << "Data empty list" << endl;
    SingleList<T> list_empty;
    showSingleList(list_empty);
    cout << "Empty: " << (list_empty.empty() ? "True" : "False") << endl;

    cout << "Data non empty list" << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    showSingleList(list);
    cout << "Empty: " << (list.empty() ? "True" : "False") << endl;
}

template <typename T> void checkBegin()
{
    cout << "Check begin:" << endl;

    cout << "Check empty list begin." << endl;
    SingleList<T> list_empty;
    cout << "Begin address: " << list_empty.begin() << endl;
    showSingleList(list_empty);

    cout << "Check non-empty list begin." << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    cout << "Begin address: " << list.begin() << endl;
    showSingleList(list);
}

template <typename T> void checkEnd()
{
    cout << "Check end:" << endl;

    cout << "Check empty list end." << endl;
    SingleList<T> list_empty;
    cout << "End address: " << list_empty.end() << endl;
    showSingleList(list_empty);

    cout << "Check non-empty list end." << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    cout << "End address: " << list.end() << endl;
    showSingleList(list);
}

template <typename T> void checkCbegin()
{
    cout << "Check cbegin:" << endl;

    cout << "Check empty list cbegin." << endl;
    SingleList<T> list_empty;
    cout << "CBegin address: " << list_empty.cbegin() << endl;
    showSingleList(list_empty);

    cout << "Check non-empty list cbegin." << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    cout << "CBegin address: " << list.cbegin() << endl;
    showSingleList(list);
}
template <typename T> void checkCend()
{
    cout << "Check cend:" << endl;

    cout << "Check empty list cend." << endl;
    SingleList<T> list_empty;
    cout << "CEnd address: " << list_empty.cend() << endl;
    showSingleList(list_empty);

    cout << "Check non-empty list cend." << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    cout << "CEnd address: " << list.cend() << endl;
    showSingleList(list);
}

template <typename T> void checkOperatorAssignment()
{
    cout << "Check operator =" << endl;

    cout << "Data original:" << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    showSingleList(list);

    cout << "Data empty list:" << endl;
    SingleList<T> list_empty;
    showSingleList(list_empty);

    cout << "Data after assignment list_empty = list_non_empty" << endl;
    list_empty = list;
    showSingleList(list_empty);
}

template <typename T> void checkOperatorEquality()
{
    cout << "Check operator ==." << endl;

    cout << "Equality empty list" << endl;
    SingleList<T> list_empty_1;
    SingleList<T> list_empty_2;
    cout << (list_empty_1 == list_empty_2 ? "True" : "False") << endl << endl;

    cout << "Equality non-empty list with non equals elements" << endl;
    cout << "Data first list: " << endl;
    SingleList<T> list_1{1, 2, 3, 4, 5};
    showSingleList(list_1);
    cout << "Data second list: " << endl;
    SingleList<T> list_2{1, 2, 3, 4, 6};
    showSingleList(list_2);
    cout << (list_1 == list_2 ? "True" : "False") << endl;

    cout << "Equality non-empty list with equals elements" << endl;
    cout << "Data third list: " << endl;
    SingleList<T> list_3{1, 2, 3, 4, 5};
    showSingleList(list_3);
    cout << "Data fourth list: " << endl;
    SingleList<T> list_4{1, 2, 3, 4, 5};
    showSingleList(list_4);
    cout << (list_3 == list_4 ? "True" : "False") << endl;
}

template <typename T> void checkOperatorIndex()
{
    cout << "Check operator []" << endl;

    cout << "Data list: " << endl;
    SingleList<T> list{1, 2, 3, 4, 5};
    showSingleList(list);

    cout << "Get value and next from 0 index" << endl;
    cout << "Value: " << list[0]->value_ << endl;
    cout << "Next: " << list[0]->next_ << endl;

    cout << "Get value and next from 2 index" << endl;
    cout << "Value: " << list[2]->value_ << endl;
    cout << "Next: " << list[2]->next_ << endl;

    cout << "Get value and next_ from 4 index" << endl;
    cout << "Value: " << list[4]->value_ << endl;
    cout << "Next: " << list[4]->next_ << endl;
}