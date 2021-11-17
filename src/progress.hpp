#ifndef _PROGRESS_H_
#define _PROGRESS_H_
#include <concepts>

#include "range.hpp"

//template <class T>
//concept Iter = std::is_base_of<Range<char>,T>::value;

template<class T>
class Progress
{
public:
    explicit Progress( T& obj ): m_obj(obj)
    {
    }
    template<class U>
    class Iterator
    {
    public:


        Iterator(U&& obj) : begin_(obj)
        {

        }

        ~Iterator() = default;
        Iterator& operator++()
        {
            begin_.operator++();
            std::cout << "*" << std::flush; 
            return *this;
        }

        U& operator*(){return begin_;}
        U* operator->(){return begin_;}

        friend bool operator!=(const Iterator & a1, const Iterator& a2) {
            return a1.begin_ != a2.begin_;
            }

        friend bool operator==(const Iterator & a1, const Iterator& a2) {
        return  a1.begin_ == a2.begin_;
        }

        private:
        U begin_;
    };

    auto begin()
    {
        return Iterator<decltype(this->m_obj.begin())>(this->m_obj.begin());
    }

    auto end()
    {
        return Iterator<decltype(this->m_obj.begin())>(this->m_obj.end());
    }

private:
    T& m_obj;
};

#endif // _PROGRESS_H_