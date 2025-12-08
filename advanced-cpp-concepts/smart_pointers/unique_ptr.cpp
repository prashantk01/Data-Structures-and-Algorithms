#include<bits/stdc++.h>
using namespace std;
#include<memory> // For std::unique_ptr and std::make_unique

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

// Function to create a unique_ptr
// Unique pointers automatically manage memory and ensure no memory leaks
// They cannot be copied, only moved
// Using make_unique is the preferred way to create unique_ptrs as it is exception-safe
// and avoids potential memory leaks in case of exceptions during object creation 
int main(){
    {
        unique_ptr<Base> ptr1 = make_unique<Base>(10); // Using make_unique to create a unique_ptr
        ptr1->show(); // Accessing member function using unique_ptr
        unique_ptr<Base> ptr2  = move(ptr1); // Transferring ownership using move semantics
        if(!ptr1){
            cout << "ptr1 is now null after move." << endl; 
        }
        ptr2->show(); // Accessing member function using the new owner
    }

    cout << "Unique pointer out of scope, destructor should have been called." << endl;
    return 0;
}