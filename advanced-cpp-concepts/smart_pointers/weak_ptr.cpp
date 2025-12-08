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

// Function to create a weak_ptr
// Weak pointers are used to break circular references that can occur with shared_ptr
// They do not affect the reference count of the object they point to
// A weak_ptr must be converted to a shared_ptr to access the object
// Using make_shared is the preferred way to create shared_ptrs as it is exception-safe
// and avoids potential memory leaks in case of exceptions during object creation
int main(){
    {
        shared_ptr<Base> sptr1 = make_shared<Base>(30); // Using make_shared to create a shared_ptr
        weak_ptr<Base> wptr1 = sptr1; // Creating a weak_ptr from shared_ptr
        cout << "Reference count after creating weak_ptr: " << sptr1.use_count() << endl; // Reference count should remain the same
        if(auto sptr2 = wptr1.lock()){ // Converting weak_ptr to shared_ptr
            sptr2->show(); // Accessing member function using the new shared_ptr
            cout << "Reference count after locking weak_ptr: " << sptr1.use_count() << endl; // Reference count should increase
        } else {
            cout << "The object has been deleted." << endl;
        }
    } // sptr1 goes out of scope here, destructor should be called          
    cout << "Weak pointer out of scope, destructor should have been called." << endl;
    return 0;
}