#ifndef _CUSTOM_SINGLE_LIST_HPP_
#define _CUSTOM_SINGLE_LIST_HPP_

#include <initializer_list>
#include <iostream>

namespace custom_stl {
// The creation of this structure is possible only dynamically.
// Freeing memory by calling the "free()" function.
template <typename T> struct SingleNode {
public:
    T value_;
    SingleNode<T> *next_;

    SingleNode() : value_(0), next_(nullptr) {}

    SingleNode(const T value) : value_(value), next_(nullptr) {}

    SingleNode(SingleNode<T> *next) : value_(0), next_(next) {}

    SingleNode(const T value, SingleNode<T> *next) : value_(value), next_(next) {}

    SingleNode(const SingleNode &other)
    {
        this->value_ = other.value_;
        this->next_ = other.next_;
    }

    // Returns a pointer for the possibility of deleting the following elements
    SingleNode *free()
    {
        SingleNode<T> *temp = this->next_;
        delete this;
        return temp;
    }

private:
    // Prohibition on static instantiation of the structure
    ~SingleNode() {}
};

template <typename T> class SingleList {
private:
    SingleNode<T> *first_;
    // Last element == first_ or != nullptr
    SingleNode<T> *last_;
    // temp_ used in intermediate calculations
    SingleNode<T> *temp_;
    unsigned int size_;

public:
    SingleList() : first_(nullptr), last_(nullptr), size_(0) {}

    SingleList(SingleNode<T> *first) : size_(1)
    {
        this->first_ = new SingleNode<T>(first->value_, nullptr);
        this->last_ = this->first_;
    }

    SingleList(std::initializer_list<T> list) : size_(list.size())
    {
        if (this->size_ != 0) {
            auto it = list.begin();
            this->first_ = new SingleNode<T>(it[0], nullptr);

            this->temp_ = this->first_;
            for (unsigned int i = 1; i < this->size_; ++i) {
                this->temp_->next_ = new SingleNode<T>(it[i], 0);
                this->temp_ = this->temp_->next_;
            }
            this->last_ = this->temp_;
        }

        toNullPtr();
    }

    SingleList(const SingleList<T> &other)
    {
        this->size_ = other.size_;
        if (this->size_ != 0) {
            this->first_ = new SingleNode<T>(other.first_->value_, nullptr);

            SingleNode<T> *temp_other = other.first_->next_;
            this->temp_ = this->first_;
            while (temp_other != nullptr) {
                this->temp_->next_ = new SingleNode<T>(temp_other->value_, nullptr);
                this->temp_ = this->temp_->next_;
                temp_other = temp_other->next_;
            }
            this->last_ = this->temp_;
        }

        toNullPtr();
    }

    void push_front(SingleNode<T> *node)
    {
        this->temp_ = node;
        if (!checkFirstAdd()) {
            addFront();
        }
    }

    void push_front(const T elem)
    {
        this->temp_ = new SingleNode<T>(elem, nullptr);
        if (!checkFirstAdd()) {
            addFront();
        }
    }

    void push_back(SingleNode<T> *node)
    {
        this->temp_ = node;
        if (!checkFirstAdd()) {
            addBack();
        }
    }

    void push_back(const T elem)
    {
        this->temp_ = new SingleNode<T>(elem, nullptr);
        if (!checkFirstAdd()) {
            addBack();
        }
    }

    void emplace_front(SingleNode<T> *&node)
    {
        this->temp_ = node;
        if (!checkFirstAdd()) {
            addFront();
        }
    }

    void emplace_front(const T &elem)
    {
        this->temp_ = new SingleNode<T>(elem, nullptr);
        if (!checkFirstAdd()) {
            addFront();
        }
    }

    void emplace_back(SingleNode<T> *&node)
    {
        this->temp_ = node;
        if (!checkFirstAdd()) {
            addBack();
        }
    }

    void emplace_back(const T &elem)
    {
        this->temp_ = new SingleNode<T>(elem, nullptr);
        if (!checkFirstAdd()) {
            addBack();
        }
    }

    void insert(SingleNode<T> *it, SingleNode<T> *node)
    {
        this->temp_ = node;
        if (!checkFirstAdd()) {
            addInsert(it);
        }
    }

    void insert(SingleNode<T> *it, const T elem)
    {
        this->temp_ = new SingleNode<T>(elem, nullptr);
        if (!checkFirstAdd()) {
            addInsert(it);
        }
    }

    void pop_front()
    {
        if (this->size_ != 0) {
            delFront();
            toNullPtr();
        }
    }

    void pop_back()
    {
        if (this->size_ != 0) {
            delBack();
            toNullPtr();
        }
    }

    void erase(SingleNode<T> *it)
    {
        if (it == this->first_) {
            pop_front();
            return;
        }
        if (it == this->last_) {
            pop_back();
            return;
        }
        if (this->size_ != 0) {
            this->temp_ = this->first_;

            while (this->temp_->next_ != it) {
                this->temp_ = this->temp_->next_;
            }
            this->temp_->next_ = it->next_;
            it->free();
            --this->size_;
        }
    }

    void clear()
    {
        while (this->first_ != nullptr) {
            this->first_ = this->first_->free();
        }
        this->size_ = 0;
        toNullPtr();
    }

    unsigned int size() { return this->size_; }

    bool empty(){
        return this->first_ == nullptr;
    }

    SingleNode<T> *begin() { return this->first_; }

    SingleNode<T> *end() { return this->last_; }

    const SingleNode<T> *cbegin() { return this->first_; }

    const SingleNode<T> *cend() { return this->last_; }

    ~SingleList()
    {
        while (this->first_ != nullptr) {
            this->first_ = this->first_->free();
        }
    }

    SingleList<T> &operator=(const SingleList<T> &other)
    {
        this->clear();

        if (other.size_ != 0) {
            SingleNode<T> *temp_other = other.first_;
            SingleNode<T> *temp_this;
            for (unsigned int i = 0; i < other.size_; ++i) {
                temp_this = new SingleNode<T>(temp_other->value_, 0);
                this->push_back(temp_this);
                temp_other = temp_other->next_;
            }
        }

        return *this;
    }

    bool operator==(const SingleList<T> &other)
    {
        if (this->size_ != other.size_) {
            return false;
        }

        SingleNode<T> *temp_this = this->first_;
        SingleNode<T> *temp_other = other.first_;

        for (unsigned int i = 0; i < this->size_; ++i) {
            if (temp_this->value_ != temp_other->value_) {
                return false;
            }
            temp_this = temp_this->next_;
            temp_other = temp_other->next_;
        }

        return true;
    }

    SingleNode<T> *operator[](unsigned int index)
    {
        this->temp_ = this->first_;

        for (unsigned int i = 0; i < index; ++i) {
            this->temp_ = this->temp_->next_;
        }

        return this->temp_;
    }

private:
    bool checkFirstAdd()
    {
        if (this->first_ == nullptr) {
            this->first_ = new SingleNode<T>(this->temp_->value_, 0);
            this->last_ = this->first_;
            this->size_ = 1;
            return true;
        }
        return false;
    }

    void toNullPtr()
    {
        if (this->size_ == 0) {
            this->first_ = nullptr;
            this->last_ = nullptr;
        }
    }

    void addBack()
    {

        this->last_->next_ = this->temp_;
        this->last_ = this->temp_;
        this->last_->next_ = nullptr;
        ++this->size_;
    }

    void addFront()
    {
        this->temp_->next_ = this->first_;
        this->first_ = this->temp_;
        ++this->size_;
    }

    void addInsert(SingleNode<T> *&it)
    {
        this->temp_->next_ = it->next_;
        it->next_ = this->temp_;
        ++this->size_;
        if (it == this->last_) {
            this->last_ = this->temp_;
        }
    }

    void delFront()
    {
        this->first_ = this->first_->free();
        --this->size_;
    }

    void delBack()
    {
        if (this->size_ != 1) {
            this->temp_ = this->first_;
            while (this->temp_->next_ != this->last_) {
                this->temp_ = this->temp_->next_;
            }
            this->temp_->next_->free();
            this->temp_->next_ = nullptr;
            this->last_ = this->temp_;
            --this->size_;
        }
        else {
            this->first_->free();
            this->size_ = 0;
            toNullPtr();
        }
    }
};
} // namespace custom_stl

#endif // _CUSTOM_SINGLE_LIST_HPP_