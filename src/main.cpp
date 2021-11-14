#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include "iterator.hpp"

class A
{
    public:

    Iterator<char> begin(){ return Iterator<char>(&m_data[0]);}
    Iterator<char> end(){return Iterator<char>(&m_data[200]);}

public:
    char m_data[200]{"Hello from my inner class"};


};

int main()
{
    std::cout << "Hello world\n";
    std::vector<int> temp({1,2,3,4,5,6});
    A a;

    for( auto it : a){
        std::cout << it;
    }
    // using namespace std::chrono_literals;
    // for( auto& it: temp){
    //     std::cout << "*" << std::flush;
    //     std::this_thread::sleep_for(1000ms);
    // }
    return 0;
}