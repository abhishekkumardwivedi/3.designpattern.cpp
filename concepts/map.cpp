#include<iostream>
#include<map>

std::map<std::string, float> get_temp()
{
    std::map<std::string, float> tmp;

    tmp.begin();
    tmp["temp"] = 25.5;
    tmp["max"] = 55.3;
    return tmp;
}

int main()
{
    std::cout << "temp: " << get_temp()["temp"] << std::endl;
    std::cout << "max: " << get_temp()["max"] << std::endl;
}