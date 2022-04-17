#include<iostream>

class shape
{
public:
    shape() = delete;
    void draw(int) = delete;
    void draw(float);
    shape(int, int);
    virtual int area() = 0;
};

void shape::draw(float a)
{
    std::cout << "shape::draw(float) \n";
}

shape::shape(int i, int j = 10)
{
    std::cout << "shape::shape(i)\n";
}

class square : public shape
{
private:
    int _l;
    int _b;
public:
    square(int l, int b) : shape(5), _l(l), _b(b)
    {
        std::cout << "square::square() \n";
    };

    int area()
    {
        return _l*_b;
    }
};

int main()
{
    std::cout << "Hello World!!" << std::endl;
    shape *s = new square(4, 5);
    // s->draw(10.0);
    std::cout << "area = " << s->area() << std::endl;

    return 0;
}