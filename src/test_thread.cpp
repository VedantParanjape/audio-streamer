#include "thread_handler.hpp"
#include <iostream>

void func(int a, int b)
{
    for(int i=0; i<b; i++)

    {std::cout << i + b;} 
}

int main()
{
    int a;
    thread_handler hndl;
    hndl.start_handle(func, 2, 3);
    hndl.start_handle(func, 4, 5);
}