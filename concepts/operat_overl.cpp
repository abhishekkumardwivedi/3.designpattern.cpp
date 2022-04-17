#include<iostream>
#include<string>

class Local {
    int _n = 0;
    int _d = 0;

public:
    Local(int, int);
    Local & operator = (const Local &);
    Local operator + (const Local &) const;
    Local operator - (const Local &) const;
    Local operator * (const Local &) const;
    Local operator / (const Local &) const;
    Local operator += (const Local &) const;
    Local operator ++ () const;
    Local operator ++ (int) const;
    void print() const;
};

Local::Local(int n, int d): _n(n), _d(d)
{}

Local & Local::operator = (const Local & local)
{
    if(this != &local) {
        _n = local._n;
        _d = local._d;
    }
    return *this;
}

Local Local::operator + (const Local & local) const
{
    return Local (this->_n + local._n, this->_d + local._d);
}

Local Local::operator ++ () const
{
    return Local( this->_n + 1, this->_d + 1);
}

Local Local::operator ++ (int) const
{
    return Local( this->_n + 1, this->_d + 1);
}

Local Local::operator - (const Local & local) const
{
    return Local (this->_n - local._n, this->_d - local._d);
}

Local Local::operator * (const Local & local) const
{
    return Local (this->_n*local._n, this->_d*local._d);
}

Local Local::operator / (const Local & local) const
{
    return Local (this->_n/local._n, this->_d/local._d);
}

void Local::print() const
{
    std::cout << "_n:" << _n << ", " << "_d:" << _d << std::endl;
}

int main()
{
    Local l1(6, 10);
    Local l2(3, 4);

    Local l3 = l1;

    (l1 + l2).print();
    (l1 - l2).print();
    (l1 * l2).print();
    (l1 / l2).print();
    l1.print();
    (++l1).print();
    (l1++).print();

    std::string s = "value is :";
}