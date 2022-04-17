#include<iostream>
#include<type_traits>

template <std::size_t W, std::size_t H>
struct grid
{
    auto & operator [] (int x, int y)
    {
        return grid[y*W + x];
    }
    int grid[W*H];
};

int main()
{
    grid<5, 5> g;
    g[1, 2] = 42;
    return 0;
}

