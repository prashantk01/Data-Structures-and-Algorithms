#include<bits/stdc++.h>
using namespace std;

/*
For the overridden function should be bound dynamically to the function body, 
we make the base class function virtual using the “virtual” keyword. 
This virtual function is a function that is overridden in the derived class and 
the compiler carries out late or dynamic binding for this function.
*/

class Parent // Parent class 
{
public:
    Parent(){  // base class constructor
        cout << " base class constructor " << endl;
    }
    virtual void print()    // base class print function
    {
        cout << " Hi, this is base class print function "<<endl;
    }
};

class Child: public Parent {  // child class publicly derived from base class
    public:
    Child(){                // child class constructor
        cout << " child class constructor " << endl;
    }
    void print(){           // child class print function which is inherited from base class
        cout << " Hi, this is child class print function " << endl;
    }
};

int main(){
    Parent *p;  // base class pointer
    Child c; // child class object
    p = &c;
    p->print(); // with virtual keword at base print function definition, it will print child class i.e dynamic binding

    return 0;
}