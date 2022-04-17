#include<iostream>

template <typename T>
int get_size_bits(const T& a)
{
    return sizeof(a)*8;
}

int main()
{
    std::cout << get_size_bits(20) << std::endl;
    std::cout << get_size_bits('20') << std::endl;
    std::cout << get_size_bits("abhishek") << std::endl;
    std::cout << get_size_bits(10.1f) << std::endl;
    std::cout << get_size_bits(10.1) << std::endl;
    return 0;
}