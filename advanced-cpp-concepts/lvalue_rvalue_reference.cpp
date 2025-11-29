// l-values
// Any object/variable with memory location that persists beyond single expression
// Can appear on left OR right side of assignment (int a = 10; int b = a;)
// Has identifiable memory address

// l-value reference
// A reference to l-value variable (int& x = a)
// Binds to lvalues, extends lifetime of object

// r-values
// Temporary values or expressions without persistent memory location
// Examples: literals (20, true), expressions (a+b), function returns (by value)
// Can only appear on RIGHT side of assignment

// r-value reference (C++11)
// A reference to r-values (int&& x = 10)
// Used for move semantics and perfect forwarding

// RULES:
// ✅ Can assign rvalue to lvalue: int a = 10
// ❌ Can't bind lvalue reference to rvalue: int& a = 10 (unless const)
// ✅ Const lvalue ref can bind to rvalue: const int& a = 10
// ✅ Rvalue reference binds to rvalue: int&& a = 10
// ✅ std::move() converts lvalue to rvalue reference

#include<iostream>

int getValue(){
    return 5; // Returns rvalue (temporary)
}

int& getReference(){
    static int x = 100;
    return x; // Returns lvalue reference
}

void print(int x){
    std::cout << "Value: " << x << std::endl;
}

int main(){
    // LVALUE EXAMPLES
    int lVariable = 10;
    std::cout << "lVariable: " << lVariable << " Address: " << &lVariable << std::endl;
    
    // LVALUE REFERENCE
    int& lReference = lVariable;  // ✅ Binding to lvalue
    std::cout << "lReference: " << lReference << " Address: " << &lReference << std::endl;
    
    // Can't bind non-const lvalue ref to rvalue
    // int& lRef2 = 10; // ❌ ERROR
    
    // Const lvalue reference CAN bind to rvalue
    const int& lRef3 = 10; // ✅ OK - lifetime extended
    std::cout << "const lvalue ref to rvalue: " << lRef3 << std::endl;
    
    // RVALUE REFERENCE
    int&& rReference = 20; // ✅ Binding to rvalue
    std::cout << "rReference: " << rReference << std::endl;
    
    // Can't directly bind rvalue ref to lvalue
    // int&& rRef2 = lVariable; // ❌ ERROR
    
    // Use std::move to convert lvalue to rvalue reference
    int&& rRef2 = std::move(lVariable); // ✅ OK
    std::cout << "Moved lvalue: " << rRef2 << std::endl;
    
    // FUNCTION RETURN VALUES
    // getValue() returns temporary (rvalue)
    int x = getValue(); // ✅ OK
    // int& ref = getValue(); // ❌ ERROR - can't bind to temporary
    const int& ref1 = getValue(); // ✅ OK - const ref extends lifetime
    int&& ref2 = getValue(); // ✅ OK - rvalue ref
    
    // getReference() returns lvalue
    int& ref3 = getReference(); // ✅ OK
    
    // EXPRESSIONS
    int a = 5, b = 10;
    int result = a + b; // ✅ (a+b) is rvalue
    // int& refExpr = a + b; // ❌ ERROR
    int&& refExpr = a + b; // ✅ OK
    
    print(getValue()); // ✅ Passing rvalue to function
    
    return 0;
}