#include<iostream>
#include<memory>
#include<cassert>

struct B
{
    virtual ~B() = default;
    virtual void bar() {std::cout << "B::bar\n"; }
};

struct D : B
{
    D() { std::cout << "D::D\n"; }
    ~D() { std::cout << "D::~D\n"; }
    void bar() override { std::cout << "D::bar\n"; }
};

std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}

void close_file(std::FILE* fp)
{
    std::fclose(fp);
}

struct List
{
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head;

    ~List()
    {
        while(head)
        {
            head = std::move(head->next);
        }      
    }

    void push(int data)
    {
        head = std::unique_ptr<Node>(new Node{data, std::move(head)});
    }
};

void hello(int *p)
{
    std::cout << "hello: " << *p << std::endl;
}

/**
 * @brief https://en.cppreference.com/w/cpp/memory/unique_ptr
 * 
 * @return int 
 */
int main()
{
    {
        std::unique_ptr<D> p = std::make_unique<D>();
        std::cout << "p: " << p.get() << std::endl;
        std::unique_ptr<D> q = pass_through(std::move(p));
        std::unique_ptr<D> r = std::make_unique<D>();
        std::cout << "r: " << r.get() << std::endl;
    }
    {
        std::unique_ptr<B> p = std::make_unique<D>();
        p->bar();
    }

    std::unique_ptr<int> foo;
    
    foo = std::unique_ptr<int>(new int(10));
    
    //https://www.cplusplus.com/reference/memory/unique_ptr/get/
    int *p = foo.get(); // memory is still managed.
    int *q = foo.release(); // memory is unmanged, need manual delete.
    hello(p);
}