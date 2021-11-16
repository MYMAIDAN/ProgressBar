#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include "iterator.hpp"
#include "range.hpp"
#include "progress.hpp"
 using namespace std::chrono_literals;

class A : public Range<char>
{
public:
    explicit A() : Range(&m_data[0],&m_data[200])
    {}
    
public:
    char m_data[200]{"Hello from my inner class"};
};

int main()
{
    std::cout << "Hello world\n";
    std::vector<int> temp({1,2,3,4,5,6});
    A a;

    for( auto it : Progress<A>(a)){
        std::this_thread::sleep_for(100ms);
    }
    // using namespace std::chrono_literals;
    // for( auto& it: temp){
    //     std::cout << "*" << std::flush;
    //     std::this_thread::sleep_for(1000ms);
    // }
    return 0;
}