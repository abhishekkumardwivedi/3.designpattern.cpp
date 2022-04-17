#include <iostream>

/**
 * @file introduction.cpp
 * @author Abhishek Dwivedi
 * @brief
 * @version 0.1
 * @date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief C++ Data types:
 * 1. Primary datatype: char, int, float, int, long, double, bool, short, etc.
 * 2. Derived datatype: array, pointer, etc.
 * 3. Enumeration: enum
 * 4. User Defined: Struct and class
 */

struct introduction_struct
{
    int a; //by default public for struct type
};

class introduction_class
{
    int a; //by default private for class type
};

typedef enum {  // have typedef and use ENUM_ATTR alone without enum keyword
    ENUM_ATTR_1,
    ENUM_ATTR_2,
    ENUM_ATTR_3
} ENUM_ATTR;

int main() {
// class default is private, struct default is public
   introduction_struct s;
   introduction_class c;
   s.a = 1;
   std::cout << s.a << std::endl;
   /**
   c.a = 2;
   std::cout << c.a << std::endl; 
   // error: 'int introduction_class::a' is private within this context
   **/
  
    return 0;
}
