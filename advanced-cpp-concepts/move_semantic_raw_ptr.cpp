#include <iostream>

class base
{
private:
    int *p;
    int size;

public:
    base()
    {
        p = nullptr;
        size = 0;
        std::cout << "default ctor called" << std::endl;
    };
    base(int s)
    { // param ctor
        std::cout << "param ctor called" << std::endl;
        p = new int[s];
        size = s;
    }

    base(const base &obj)
    { // copy ctor - deep copy
        size = obj.size;
        this->p = size > 0 ? new int[size] : nullptr;
        for (int i = 0; i < size; i++)
        {
            this->p[i] = obj.p[i];
        }
        std::cout << "copy ctor called" << std::endl;
    }
    base &operator=(const base &obj)
    { // copy assignment
        if (this != &obj)
        {
            delete[] p;
            size = obj.size;
            p = size > 0 ? new int[size] : nullptr;
            for (int i = 0; i < size; i++)
            {
                p[i] = obj.p[i];
            }
        }
        std::cout << "copy assignment called" << std::endl;
        return *this;
    }

    base(base &&obj) noexcept
    { // move ctor enabled by rvalue ref
        this->p = obj.p;
        this->size = obj.size;
        obj.p = nullptr;
        std::cout << "move ctor called" << std::endl;
        obj.size = 0;
    }
    base &operator=(base &&obj) noexcept
    { // move assignment
        if (this != &obj)
        {
            delete[] p;
            this->p = obj.p;
            this->size = obj.size;
            obj.p = nullptr;
            obj.size = 0;
        }
        std::cout << "move assignment called" << std::endl;
        return *this;
    }

    ~base()
    {
        delete[] p;
    };
};

int main()
{
    base a(5);  // param ctor
    base b = a; // copy ctor
    base c;
    c = a;                 // copy assignment - should allow deep copy
    base d = std::move(a); // move ctor
    base e;
    e = std::move(b); // move assignment
    return 0;
}