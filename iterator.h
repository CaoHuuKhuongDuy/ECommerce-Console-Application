#pragma once

#include <vector>

template <typename T, typename U>
class Iterator {
public:
    typedef typename std::vector<T>::iterator iter_type;
    Iterator(U *p_data, bool reverse = false);

    void First();
    void Next();
    bool IsDone();
    iter_type Current();

private:
    U *m_p_data_;
    iter_type m_it_;
};

template <typename T, typename U>
Iterator<T, U>::Iterator(U *p_data, bool reverse) : m_p_data_(p_data) {
    m_it_ = m_p_data_->m_data_.begin();
}

template <typename T, typename U>
void Iterator<T, U>::First() {
    m_it_ = m_p_data_->m_data_.begin();
}

template <typename T, typename U>
void Iterator<T, U>::Next() {
    m_it_++;
}

template <typename T, typename U>
bool Iterator<T, U>::IsDone() {
    return (m_it_ == m_p_data_->m_data_.end());
}

template <typename T, typename U>
typename Iterator<T, U>::iter_type Iterator<T, U>::Current() {
    return m_it_;
}

