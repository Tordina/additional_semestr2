#include <iostream>
#include <memory>
#include <vector>
//класс родителя
class Foo 
{
private:
    std::vector<int> m; //int* -> std::vector && i -> m

public:
    Foo(int j) 
    {
        std::cout << "Foo constructor" << std::endl;
        for (int i = 0; i < j; i++)// <- i = new int[j]
        { 
            m.push_back(i);
        }
    }
    virtual ~Foo()// добавлен virtual
    { 
        std::cout << "Foo destructor" << std::endl;
        // удалено "delete i"
    }
    void get() // вывод 
    { 
        for (auto i : m) 
        {
            std::cout << m[i] << std::endl;
        }
    }
};
//класс предка
class Bar : public Foo //добавлен public
{ 
private:
    std::vector<char> k; //char* -> std::vector<char> && i ->k

public:
    Bar(int j) : Foo(j) // добавлено : Foo(j)
    {
        std::cout << "Bar constructor" << std::endl;
        k.push_back((char)j); // <- i = new char[j]
    }
    virtual ~Bar() //добавлен virtual
    { 
        std::cout << "Bar destructor" << std::endl;
        //удалено "delete i"
    }

};
int main() { // void -> main

    std::unique_ptr<Foo> f = std::make_unique<Foo>(5); // <- Foo* f=new Foo(100);
    std::unique_ptr<Foo> b = std::make_unique<Bar>(2); // <- Foo* b=new Bar(200);

    //добавлен вывод
    std::cout << "Foo=" << std::endl;
    f->get();
    std::cout << "Bar=" << std::endl;
    b->get();

    *f = *b;

    std::cout << "Foo=" << std::endl;
    f->get();
    std::cout << "Bar=" << std::endl;
    b->get();
};

