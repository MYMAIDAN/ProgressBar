#ifndef _ITERATOR_H_
#define _ITERATOR_H_

template <class T>
class Iterator
{
public:
    explicit Iterator(T* data): m_data(data){};
    ~Iterator() = default;
    T& operator*(){return *m_data;}
    T* operator->(){return m_data;}

    Iterator& operator++(){m_data++; return *this;}

    friend bool operator!=(const Iterator<T> & a1, const Iterator<T>& a2) {
    return a1.m_data != a2.m_data;}

    friend bool operator==(const Iterator<T> & a1, const Iterator<T>& a2) {
    return  a1.m_data == a2.m_data;
}

private:
    T* m_data{nullptr};
};





#endif // _ITERATOR_H_