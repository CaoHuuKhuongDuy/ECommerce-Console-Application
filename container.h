#pragma once

#include "Iterator.h"

template <class T>
class Container {
    friend class Iterator<T, Container>;

public:
    void add(T a);
    Iterator<T, Container> *CreateIterator();
    T &operator[](int index);
    int size() const;
    void clear();
    void erase(size_t index);

private:
    std::vector<T> m_data_;
};

template <class T>
void Container<T>::add(T a) {
    m_data_.push_back(a);
}

template <class T>
Iterator<T, Container<T>> *Container<T>::CreateIterator() {
    return new Iterator<T, Container<T>>(this);
}

template <class T>
T &Container<T>::operator[](int index) {
    return m_data_[index];
}

template <class T>
int Container<T>::size() const {
    return m_data_.size();
}

template <class T>
void Container<T>::clear() {
    m_data_.clear();
}

template <class T>
void Container<T>::erase(size_t index) {
    m_data_.erase(m_data_.begin() + index);
}