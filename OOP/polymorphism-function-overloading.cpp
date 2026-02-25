#include <iostream>
// Compile time polymmorphism - Function overloading
class Base
{
private:
    int data;

public:
    void set(int x)
    {
        this->data = x;
    }
    int add(int x)
    {
        return this->data + x;
    }
    int add(int x, int y)
    {
        return this->data + x + y;
    }
    float add(float x)
    {
        return this->data + x;
    }
};

int main()
{
    Base b;
    b.set(10);
    std::cout << b.add(10) << std::endl;     // print 20
    std::cout << b.add(10, 10) << std::endl; // print 30
    std::cout << b.add(10.5f) << std::endl;  // print 20 as float is converted to int
    return 0;
}