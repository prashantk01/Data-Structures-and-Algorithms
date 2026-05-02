#include <iostream>
#include <memory>
class SharedPtr
{
private:
    int *ptr = nullptr;
    int *refCount = nullptr;

public:
    // default constructor
    SharedPtr()
    {
        ptr = new int(10);
        refCount = new int(1);
    }

    // copy constructor
    SharedPtr(const SharedPtr &obj)
    {
        ptr = obj.ptr;
        refCount = obj.refCount;
        if (refCount)
        {
            (*refCount)++;
        }
    }

    // copy assignment
    SharedPtr &operator=(const SharedPtr &obj)
    {
        if (this != &obj)
        {
            releaseResource();
            ptr = obj.ptr;
            refCount = obj.refCount;
            if (refCount)
            {
                (*refCount)++;
            }
        }
        return *this;
    }

    // move constructor
    SharedPtr(SharedPtr &&other) noexcept
    {
        ptr = other.ptr;
        refCount = other.refCount;
        other.ptr = nullptr;
        other.refCount = nullptr;
    }

    // move assignment
    SharedPtr &operator=(SharedPtr &&other) noexcept
    {
        if (this != &other)
        {
            releaseResource();
            ptr = other.ptr;
            refCount = other.refCount;
            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }

    // destructor
    ~SharedPtr()
    {
        releaseResource();
    }
    void releaseResource()
    {
        // release current resource
        if (refCount)
        {
            (*refCount)--;
            if (*refCount == 0)
            {
                delete ptr;
                delete refCount;
            }
        }
        ptr = nullptr;
        refCount = nullptr;
    }

    int getRefCount() const
    {
        return refCount ? *refCount : 0;
    }
    void showData() const
    {
        if (ptr)
            std::cout << "shared data: " << *ptr << std::endl;
        else
            std::cout << "null\n";
    }
};

int main()
{
    // class based implementation
    SharedPtr p1;
    SharedPtr p2 = p1;
    p1.showData();
    p2.showData();
    std::cout << p1.getRefCount() << std::endl; // should print 2
    SharedPtr p3 = std::move(p1);
    std::cout << p1.getRefCount() << std::endl; // should print 0
    std::cout << p2.getRefCount() << std::endl; // should print 2

    // using stl implementation of shared ptr
    std::shared_ptr<int> pt1 = std::make_shared<int>(10);
    {
        std::shared_ptr<int> pt2 = pt1;
        std::cout << pt1.use_count() << std::endl; // should print 2
    }
    std::cout << pt1.use_count() << std::endl; // should print 1
    return 0;
}