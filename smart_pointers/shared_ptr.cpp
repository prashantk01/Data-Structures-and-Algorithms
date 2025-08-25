#include<bits/stdc++.h>
using namespace std;
#include<memory> // For std::shared_ptr and std::make_shared

class Base{
    private:
        int data;
    public:
        Base() {}
        Base(int x)
        {
            data = x;
            cout << "Parameterized constructor of base class called with value: " << data << endl;
        }
        ~Base(){
            cout << "Destructor of base class called" << endl;
        }
        void show(){
            cout << "Data: " << data << endl;
        }
};

// Function to create a shared_ptr
// Shared pointers allow multiple pointers to share ownership of an object
// They keep a reference count to manage the object's lifetime
// Using make_shared is the preferred way to create shared_ptrs as it is exception-safe
// and avoids potential memory leaks in case of exceptions during object creation
int main(){
    {
        shared_ptr<Base> ptr1 = make_shared<Base>(20); // Using make_shared to create a shared_ptr
        ptr1->show(); // Accessing member function using shared_ptr
        {
            shared_ptr<Base> ptr2 = ptr1; // Copying shared_ptr increases the reference count
            cout << "Reference count after copying ptr1 to ptr2: " << ptr1.use_count() << endl;
            ptr2->show(); // Accessing member function using the new owner
        } // ptr2 goes out of scope here, reference count decreases
        cout << "Reference count after ptr2 goes out of scope: " << ptr1.use_count() << endl;
    } // ptr1 goes out of scope here, destructor should be called           
    cout << "Shared pointer out of scope, destructor should have been called." << endl;
    return 0;
}

