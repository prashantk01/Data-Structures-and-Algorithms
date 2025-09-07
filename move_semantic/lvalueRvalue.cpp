#include<iostream>

void foo(int& x){ // lvalue reference
    std::cout << " lvalue reference function called: " << x << std::endl;
    x++; // modifying the value of x
}

void foo(int&& x){ // rvalue reference
    std::cout << " rvalue reference function called: " << x << std::endl;
    x++; // modifying the value of x
}

int main(){
    int x = 10; // x is an lvalue and 5 is an rvalue
    int y = x; // lvalue to lvalue assignment

    int &a = x; // lvalue reference, a is an alias for x
    a++; // modifying x through a
    std::cout << " value of x after modifying a: " << x << std::endl;

    int &&b = 20; // rvalue reference, b is an alias for the temporary rvalue 20
    b++; // modifying the temporary rvalue through b
    std::cout << " value of b after modifying b: " << b << std::endl;

    foo(x); // calls lvalue reference function
    foo(30); // calls rvalue reference function

    // int &&c = x; // lvalue x cannot bind to rvalue reference c
    int &&c = std::move(x); // std::move converts lvalue x to rvalue, so it can bind to rvalue reference c
    c++; // modifying x through c
    std::cout << " value of x after modifying c: " << x << std::endl;
}