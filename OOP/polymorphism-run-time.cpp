#include<bits/stdc++.h>
using namespace std;

/*
For the overridden function should be bound dynamically to the function body, 
we make the base class function virtual using the “virtual” keyword. 
This virtual function is a function that is overridden in the derived class and 
the compiler carries out late or dynamic binding for this function.
*/

class Base // Base class 
{
public:
    Base(){  // base class constructor
        cout << " base class constructor " << endl;
    }
    virtual void print()    // base class print function
    {
        cout << " Hi, this is base class print function "<<endl;
    }
};

class Child: public Base {  // child class publicly derived from base class
    public:
    Child(){                // child class constructor
        cout << " child class constructor " << endl;
    }
    void print(){           // child class print function which is inherited from base class
        cout << " Hi, this is child class print function " << endl;
        // Base::print(); // this will invoke print function from Base class
    }
};

int main(){
    Base *b;  // base class pointer
    Child c; // child class object
    b = &c;
    b->print(); // with virtual keword at base print function definition, it will print child class i.e dynamic binding

    return 0;
}