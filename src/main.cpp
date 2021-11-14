#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

int main()
{
    std::cout << "Hello world\n";
    std::vector<int> temp({1,2,3,4,5,6});

    using namespace std::chrono_literals;
    for( auto& it: temp){
        std::cout << "*" << std::flush;
        std::this_thread::sleep_for(1000ms);
    }
    return 0;
}