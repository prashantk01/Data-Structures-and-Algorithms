#include <bits/stdc++.h>
using namespace std;

/*
in below program, the variable a has been made private.
It can be accessed and manipulated using only the functions get() and set()present inside the class.
Therefore, the variable a and functions get() and set()are wrapped together,
which is nothing but what encapsulation is all about.
Data hiding is part of encapsulation as the data members of the class are hidden from other classes and can be accessed only through the member functions of their own class.
source: https://www.upgrad.com/blog/encapsulation-in-oops/
*/

class A
{
private:
    int n; // private field that can not be accessed directly
public:
    void set(int x)
    { // setter
        n = x;
    }
    int get()
    { // getter
        return n;
    }
};

int main()
{
    A a;
    // cout << a.n; // will throw error as it is private
    a.set(5);
    cout << "element in class A is: " << a.get();
    return 0;
}