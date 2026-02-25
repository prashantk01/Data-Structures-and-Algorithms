#include <iostream>
// Compile time polymmorphism - Operator overloading
class Base
{
private:
    int data;

public:
    Base(int x) { data = x; }

    void set(int x) { this->data = x; }
    int get() const { return data; }

    // Arithmetic operators
    Base operator+(const Base &other)
    {
        return Base(this->data + other.data);
    }

    Base operator+(int x)
    {
        return Base(this->data + x);
    }

    Base operator-(const Base &other)
    {
        return Base(this->data - other.data);
    }

    // Comparison operator
    bool operator==(const Base &other)
    {
        return this->data == other.data;
    }

    // Increment operator
    Base &operator++()
    { // prefix
        ++data;
        return *this;
    }

    // Stream operator (as friend)
    friend std::ostream &operator<<(std::ostream &os, const Base &obj)
    {
        os << obj.data;
        return os;
    }
};

int main()
{
    Base b1(10), b2(20);

    std::cout << "b1: " << b1 << std::endl;               // 10
    std::cout << "b2: " << b2 << std::endl;               // 20
    std::cout << "b1 + b2: " << (b1 + b2) << std::endl;   // 30
    std::cout << "b1 + 5: " << (b1 + 5) << std::endl;     // 15
    std::cout << "++b1: " << (++b1) << std::endl;         // 11
    std::cout << "b1 == b2: " << (b1 == b2) << std::endl; // 0 (false)

    return 0;
}