#include<iostream>

using namespace std;

class A {
    string _type;
    string _name;
    string _sound;

public:
    A();
    A(const string & type, const string & name, const string & sound);
    A(const A &);
    A & operator = (const A &);
    void set_name(const string & name);
    void print(void);

};

A::A(const string & type, const string & name, const string & sound)
{
    _type = type;
    _name = name;
    _sound = sound;
}

A::A(const A & a)
{
    this->_name = a._name;
    this->_type = a._type;
    this->_sound = a._sound;
}

A & A::operator = (const A & a)
{
    _name = a._name;
    _type = a._type;
    _sound = a._sound;
}

void A::set_name(const string & name)
{
    _name = name;
}

void A::print()
{
    cout << _name << endl;
    cout << _type << endl;
    cout << _sound << endl;
}


int main()
{
    A a("anim", "wild", "ord");
    A b (a);
    A c = a;
    a.set_name("a.name");
    a.print();
    b.print();
    c.print();
    return 0;
}