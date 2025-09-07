#include<iostream>
class base {
    public:
    void display(){
        std::cout << "base class display function called" << std::endl;
    }
    virtual void foo() = 0; // pure virtual function, makes this class abstract
};

class child: public base{
    public:
    void foo(){
        std::cout << "child class foo function called" << std::endl;
    }
};
int main()
{
    child c;
    c.foo();
    c.display();
    // base b; // cannot create object of abstract class
    base *b; // can create pointer of abstract class
    b = &c;
    b->foo();
    b->display();
    return 0;
}

// Abstract classes cannot be instantiated, i.e., we cannot create objects of abstract classes.
// They can have pure virtual functions (functions with =0) which must be overridden in derived classes.
// Abstract classes can have regular member functions as well.
// We can create pointers of abstract classes and use them to point to derived class objects.
// Abstract classes are used to define interfaces in C++.
// Hides implementation details and shows only essential features of the object which is useful in reducing complexity and increasing efficiency.