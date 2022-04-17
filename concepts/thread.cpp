#include<iostream>
#include<thread>

void hello(int a)
{
    while(a-- != 0)
    {
        std::cout << std::endl << a + 1 << ". hello ..";
    }
}

void foo()
{
    std::cout << std::endl << "foo ..";
}

void bar(int a)
{
    while(a-- != 0)
    {
        std::cout << std::endl << a + 1 << ". bar ..";
    }
}

int main()
{
    std::thread first(foo);
    std::thread second(bar, 25);
    std::thread third(hello, 25);

    first.join();
    second.join();
    third.join();

    std::cout << "hello world" << std::endl;
}