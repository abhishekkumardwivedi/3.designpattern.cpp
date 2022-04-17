#include<iostream>
#include<memory>
#include<array>
#include<vector>
#include<list>
#include<map>              //map, multimap
#include<unordered_map>
#include<set>              //set, multiset
#include<unordered_set>
#include<stack>
#include<queue>

#include<algorithm>

#define print_array(s, X) std::cout<< s << ":"; for(auto ai : X) {std::cout << ai << "  "; }; std::cout<<std::endl;
#define print(s, X) std::cout << s << ":" << X << std::endl;

void std_array()
{
    std::array<int, 3> a1 {{1, 2, 3}};
    std::array<std::string, 2> a2 {std::string("a"), "b"};
    std::array<int, 3> a3 {{1, 2, 3}};

    print_array("a1\t\t", a1);
    std::reverse(a1.begin(), a1.end());
    print_array("a1 reverse\t", a1);
    std::sort(a1.begin(), a1.end());
    print_array("a1 sort\t\t", a1);
    print("a1 front\t", a1.front());
    print("a1 end\t\t", a1.back());
    //print_array("a1 data\t", a1.data());
    print("a1 size\t\t", a1.size());
    print("a1 max_size\t", a1.max_size());
    a1.swap(a3);
    print_array("a1 swap\t\t", a1);

    print_array("a2\t\t", a2);
    print_array("a3\t\t", a3); //extra size will be filled with zeros 
}

#define print_vector(s, X) std::cout << s << ":" ;\
 for(auto vi : X) std::cout << vi << " "; std::cout << std::endl;
void std_vector()
{
    std::vector<int> a1 {1, 2, 3};
    print_vector("a1\t\t", a1);
    a1.push_back(4);
    print_vector("a1\t\t", a1);
    a1.pop_back();        
    print_vector("a1\t\t", a1);      
    print_vector("a1\t\t", a1);        
}

/**
 * @brief std::set
 * Contains only unique elements and doesn't allow duplication. Can contain
 * element of any specified type. Internally stores element in balanced binary tree.
 * Keeps the inserted element in sorted order based on < or passed comparator.
 * xtree as base class implements iterator and operator overloadings.
 */
void std_set()
{
    std::set <std::string> nums;
    nums.insert("one");
    nums.insert("two");
    nums.insert("three");
    nums.insert("four");
    nums.insert("two");

    for(auto si : nums) { std::cout << si << "  "; std::cout << std::endl; }

    // above si could also be initialized as
//    std::set <std::string>::iterator si = nums.begin();
//    std::set <std::string>::iterator si = nums.find("two");
}

/**
 * @brief std::list
 * List container allow insert and delete element
 * iterate in both direction
 * made of doubly linked list
 * similar to forward_list (made of singly linked list) which is unidirectional interatable  
 * comparision to array, vector, dequeue, better in performing insert, extract, moving element
 * whithin the container.
 * Drawback: list and forward_list doesn't give direct access to the element by index and need
 * iteration to get their. No fast random access but sequential access.
 */
#define print_list(s, X) std::cout << s <<": " << std::endl; for(auto ai : X) { std::cout << ai << " ";} std::cout << std::endl;
void std_list()
{
    std::list<std::string> a1 = {"hello", "how", "are", "you"};
    std::list<std::string> a2 = {"hmm", "you", "brought", "from"};

    #define a1_print print_list("a1", a1);
    #define a2_print print_list("a2", a2);

    a1_print;
    a1.swap(a2);
    a1_print;
    a2_print;

    a1.push_front("hai..");
    a1.push_back("today.");
    a1.swap(a2);

    a2_print;
    a2.pop_back();
    a2.pop_front();
    a2_print;
    a1.merge(a2);
    a1_print;
    a2_print; // after merge into a1 above, a2 will be empty.
    a1.sort();
    a1_print;
    a1.unique();
    a1_print;
    a1.reverse();
    a1_print;
    a1.clear();
    a2.clear();

    a1.push_back("one");
    a1.push_back("two");
    a1.push_back("three");
    a2.push_back("ten");
    a2.push_back("twenty");
    a2.push_back("thirty");
    a1_print;
    a2_print;
    auto it = a1.begin();
    std::advance(it, 2);
    std::cout << "it:\n" << *it << std::endl;
    a1.splice(it, a2);
    a1_print;
    a2_print;
    a2.splice(a2.begin(), a1, it, a1.end());
    a1_print;
    a2_print;
}

/**
 * @brief std::multimap
 * 
 * Multiple elements with same keys are possible
 * Multiple key-value pairs are not mandatory to be unique
 * Always keeps all the keys in sorted order.
 * Apart from above deviations, it is similar to std::map
 * 
 * https://www.geeksforgeeks.org/multimap-associative-containers-the-c-standard-template-library-stl/
 * 
 */
void std_multimap()
{
    //begin(), end(), size(), max_size(), empty(), pair()
    std::multimap<int, std::string> a1;
    std::cout << "a1.size : " << a1.size() << std::endl;
    std::cout << "a1.max_size : " << a1.max_size() << std::endl;

    a1.insert(std::pair<int, std::string>(0, "zero"));
    std::cout << "a1.size : " << a1.size() << std::endl;
    std::cout << "a1.max_size : " << a1.max_size() << std::endl;

    a1.insert(std::pair<int, std::string>(2, "two"));
    a1.insert(std::pair<int, std::string>(5, "five"));
    a1.insert(std::pair<int, std::string>(1, "one"));
    a1.insert(std::pair<int, std::string>(6, "six"));
    a1.insert(std::pair<int, std::string>(4, "four"));
    std::cout << "a1.size : " << a1.size() << std::endl;
    std::cout << "a1.max_size : " << a1.max_size() << std::endl;

    /* see if a1 elements are in shorted order */
    std::cout << "a1:\n";
    for(auto it : a1) { std::cout << it.first << " " << it.second << std::endl; }

    /* = operator overloaded by multimap */
    auto a2 = a1;
    std::cout << "a2:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }

    /* find element and delete, to demonstrate programming mistake */
    a2.erase(a2.begin(), a2.find(3));
    //since, didn't find 3, it will rease all, since iterator has reached to the end.
    std::cout << "a2:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }

    /* restore a2 with a1 and then erase one element with given key */
    a2 = a1;
    std::cout << "a2:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }
    a2.erase(4);
    std::cout << "a2:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }

    /* check duplicate key-value, only duplicate key. It is allowed */
    a2.insert(std::pair<int, std::string>(5, "five"));
    a2.insert(std::pair<int, std::string>(5, "Five."));
    a2.insert(std::pair<int, std::string>(5, "Five.."));
    a2.insert(std::pair<int, std::string>(5, "Five..."));
    std::cout << "a2:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }

    /* todo: check for reverse start, end and iteration methods */
}

/**
 * @brief std::map
 * 
 * Keys must be unique, otherwise use multimap.
 * Always keeps all the keys in sorted order.
 * Apart from above deviations, it is similar to std::map
 * 
 * https://www.geeksforgeeks.org/multimap-associative-containers-the-c-standard-template-library-stl/
 * 
 */
void std_map()
{
    //begin(), end(), size(), max_size(), empty(), pair()
    std::map<int, std::string> a1;
    std::cout << "a1.size : " << a1.size() << std::endl;
    std::cout << "a1.max_size : " << a1.max_size() << std::endl;

    a1.insert(std::pair<int, std::string>(0, "zero"));
    std::cout << "a1.size : " << a1.size() << std::endl;
    std::cout << "a1.max_size : " << a1.max_size() << std::endl;

    a1.insert(std::pair<int, std::string>(2, "two"));
    a1.insert(std::pair<int, std::string>(5, "five"));
    a1.insert(std::pair<int, std::string>(1, "one"));
    a1.insert(std::pair<int, std::string>(6, "six"));
    a1.insert(std::pair<int, std::string>(4, "four"));

    std::cout << "a1.size : " << a1.size() << std::endl;
    std::cout << "a1.max_size : " << a1.max_size() << std::endl;

    /* see if a1 elements are in shorted order */
    std::cout << "a1:\n";
    for(auto it : a1) { std::cout << it.first << " " << it.second << std::endl; }

    /* = operator overloaded by multimap */
    auto a2 = a1;
    std::cout << "a2:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }

    /* find element and delete, to demonstrate programming mistake */
    a2.erase(a2.begin(), a2.find(3));
    //since, didn't find 3, it will rease all, since iterator has reached to the end.
    std::cout << "a2:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }

    /* restore a2 with a1 and then erase one element with given key */
    a2 = a1;
    std::cout << "a2:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }
    a2.erase(4);
    std::cout << "a2:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }

    /* check duplicate key-value, only duplicate key. It is allowed */
    a2.insert(std::pair<int, std::string>(5, "five"));
    a2.insert(std::pair<int, std::string>(5, "Five."));
    a2.erase(5); //have to erase to re-insert value
    a2.insert(std::pair<int, std::string>(5, "Five.."));
    a2.insert(std::pair<int, std::string>(5, "Five..."));
    std::cout << "a2:multiple key-value map entries:\n";
    for(auto it : a2) { std::cout << it.first << " " << it.second << std::endl; }

    /* todo: check for reverse start, end and iteration methods */
}

/**
 * @brief std::queue
 * FIFO
 * Push from one side and collect at the other side.
 * 
 */
void std_queue()
{
    // push, pop, front, back, empty, size, swap
    std::queue<std::string> a1;

    a1.push("hello,");
    a1.push("how");
    a1.push("are");
    a1.push("you!");

    std::cout << a1.size() << std::endl;
    std::cout << "front:" << a1.front() << std::endl;
    std::cout << "back:" << a1.back() << std::endl;
    a1.pop();

    std::cout << "front:" << a1.front() << std::endl;
    std::cout << "back:" << a1.back() << std::endl;
}

/**
 * @brief std::stack
 * LIFO
 * 
 */
void std_stack()
{
    //push, pop, front, back, empty, size, swap
}

int main()
{
    if(0) std_array();
    if(0) std_vector();
    if(0) std_set();
    if(0) std_list();
    if(0) std_multimap();
    if(0) std_map();
    if(0) std_queue();

    // std_dequeue();
    // std_forward_list();
    // std_stack();
    // std_unordered_map();
    // std_unordered_set();

    return 0;
}