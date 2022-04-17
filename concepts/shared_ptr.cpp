#include<iostream>
#include<memory>

int random_test(std::string* x)
{
    std::cout << x << std::endl;
    return 0;
}

int main()
{
    auto a = std::make_shared<std::string>("how are you");
//    std::shared_ptr<std::string> c(new std::string("a great day")); //other way, not so recommended.
    auto x = std::make_unique<std::string>("how do you do");

    auto y = std::move(x);
    std::cout << *y << std::endl;
    y.reset();
    // std::cout << *y << std::endl;

    {
        auto b = a;
        std::cout << a.use_count() << std::endl;
        std::cout << b.use_count() << std::endl;    
    }
    random_test(std::move(a));
    std::cout << a.use_count() << std::endl;

    return 0;
}