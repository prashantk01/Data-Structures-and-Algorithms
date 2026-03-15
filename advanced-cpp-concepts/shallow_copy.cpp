#include <iostream>

class Base
{
    int *data;

public:
    Base()
    {
        data = new int[5]{1, 2, 3, 4, 5};
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
    ~Base()
    {
        delete data;
    }
};
int main()
{
    Base b1;
    b1.display();
    Base b2 = b1;
    b2.display();
    /* here this program will throw an error because when we copy b1 to b2, the pointer data is copied as it is (shallow copy),
    so both b1 and b2 point to the same memory location. When the destructor is called for b1 and b2,
    it will try to delete the same memory location twice, leading to undefined behavior.
    To fix this issue, we need to implement a deep copy by defining a copy constructor that allocates new memory and
    copies the contents of the array instead of just copying the pointer.
    */
    return 0;
}