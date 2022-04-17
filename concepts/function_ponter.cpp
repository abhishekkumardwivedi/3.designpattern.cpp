#include<iostream>
#include<vector>

using namespace std;

//Example: hardware/broadcom/wlan/bcmdhd/wifi_hal/wifi_hal.cpp
void print_hello() {
    cout << " hello " << endl;
}

void print_world() {
    cout << " world " << endl;
}

class fn_pointers {
    public:
        void (*hello)();
        void (*world)();
};

int main() {
    fn_pointers fn;
    // std::vector<(*)(void)> fn_vctr;
    fn.hello = print_hello;
    fn.world = print_world;
    // fn_vctr.push_back(fn.hello);
    // fn_vctr.push_back(fn.world);
    fn.hello();
    fn.world();
    // fn_vctr.at(0);
    // fn_vctr.at(1); 
    return 0;
}