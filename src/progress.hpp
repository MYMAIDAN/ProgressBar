#ifndef _PROGRESS_H_
#define _PROGRESS_H_
#include <concepts>

#include "range.hpp"

template <class T>
concept Iter = std::is_base_of<Range<char>,T>::value;

template<Iter T>
class Progress
{
public:
    explicit Progress( const T& obj ): m_obj(obj)
    {
    }

    decltype(T::begin()) begin()
    {
        return m_obj.begin();
    }

    decltype(T::end()) end()
    {
        return m_obj.end();
    }

private:
    T& m_obj;
};

#endif // _PROGRESS_H_