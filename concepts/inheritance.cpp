#include<iostream>

class Animal {

    std::string _name;
    std::string _type;
    std::string _sound;
    Animal(){}
protected:
    Animal(const std::string & name, const std::string & type, const std::string & sound );
public:
    void speak() const;
    std::string name() const;
    std::string type() const;
    std::string sound() const;
};

Animal::Animal(const std::string & name, const std::string & type, const std::string & sound ):
_name(name), _type(type), _sound(sound)
{}

void Animal::speak() const
{
    std::cout << _name << " the " << _type << " speaks " << _sound << std::endl;
}

std::string Animal::name() const
{
    return _name;
}

std::string Animal::type() const
{
    return _type;
}

std::string Animal::sound() const
{
    return _sound;
}

class Dog : public Animal
{
    int _walk = 0;
public:
    Dog(const std::string & name, const std::string & sound): Animal(name, "dog", sound) {}
    int walk();
};

int Dog::walk()
{
    return ++_walk;
}

class Cat : public Animal
{
    int _pat;
public:
    Cat(const std::string & name, const std::string & sound) : Animal(name, "cat", sound) {}
    int pat();
};

int Cat::pat()
{
    return ++_pat;
}

int main()
{
    Dog d("Tom", "bark");

    std::cout << d.name() << " " << d.type() << " " << d.sound() << " " << d.walk() << std::endl;
    std::cout << d.name() << " " << d.type() << " " << d.sound() << " " << d.walk() << std::endl;
    return 0;
}