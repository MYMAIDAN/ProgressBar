#ifndef _RANGE_H_
#define _RANGE_H_

#include "iterator.hpp"

template <class T>
class Range
{
public:
    explicit Range(T* begin, T* end):
        m_begin(begin),
        m_end(end)
    {}

    Iterator<T> begin()
    {
        return Iterator<T>(m_begin);
    };

    Iterator<T> end()
    {  
        return Iterator<T>(m_end);

    }


private:
    T* m_begin{nullptr};
    T* m_end{nullptr};


};

#endif // _RANGE_H_