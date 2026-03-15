#include <iostream>

class Singleton
{
private:
    static inline Singleton *instancePtr = nullptr;           // inline init of static member (C++17)
    Singleton() { std::cout << "ctor invoked" << std::endl; } // private constructor to prevent external instantiation

public:
    static Singleton *getInstance()
    {
        if (instancePtr != nullptr)
            return instancePtr;        // return existing instance if already created
        instancePtr = new Singleton(); // create new instance if not created yet
        return instancePtr;
    }
    void display()
    {
        std::cout << "welcome to singleton class" << std::endl;
    }
};

int main()
{
    Singleton *obj = Singleton::getInstance(); // get the singleton instance
    obj->display();                            // call a method on the singleton instance
    return 0;
}