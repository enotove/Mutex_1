// Mutex_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
using namespace std::chrono_literals;
std::atomic<int> x(0);

void PersonInLine()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(1s);
        x.fetch_add(1);
        std::cout << x.load() << "\t";
    }
}
void PersonOutLine()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(2s);
        x.fetch_sub(1);
        std::cout << x.load() << "\t";
    }
}

int main()
{
    std::thread t1(PersonInLine);
    std::thread t2(PersonOutLine);
    t1.join();
    t2.join();
}
