#include<iostream>

/**
 * @brief C++ Casting
 * * static_cast<>()  : 
 * * dynamic_cast<>() :
 *   To use casting in class hierarchy appropriatly, for runtime type identification (RTTI).
 * * reinterpret_cast<>()
 */

class B
{
public:
    B() {std::cout << "B()" << std::endl;}
    void virtual f() {std::cout << "B::f()" << std::endl;}
};

class D1 : public B
{
public:
    D1(){std::cout << "D1()" << std::endl;}
    void f() {std::cout << "D1::f()" << std::endl;}
};

class D2 : public B
{
public:
    D2(){std::cout << "D2()" << std::endl;}
    void f() {std::cout << "D2::f()" << std::endl;}
};

void f(B* arg)
{
    D1 * dp1 = dynamic_cast<D1 *>(arg); //only casted if obj is D1 type, null for D2 and B
    D2 * dp2 = dynamic_cast<D2 *>(arg); //only casted if obj is D2 type, null for D1 and B

    if(dp1) dp1->f();
    else if(dp2) dp2->f();
    else arg->f();
}

int main()
{
    B bo;
    D2 d2o;
    D1 d1o;
    B* bd2 = &d2o; // base pointer and assigned with derived : upcasting and downcasting
    B* b = &bo;    // base pointer and assigned with base    : only upcasting
    B* bd1 = &d1o;

    f(bd2);
    f(b);
    f(bd1);

    return 0;
}