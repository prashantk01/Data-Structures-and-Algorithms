### lvalue & rvalue?
```
lvalue are object with stable identity and memory location - int x.

lvalue reference: int& x, which can bind to lvalue. int& y = x, but rvalue cannot be assigned to lvalue reference.

But if lvalue reference is const then it can be assigned. 
lvalue reference is used in copy assignment and copy constructor.
```
```
rvalue are temporary value that does not have a stable identity.

int x = 10, 10 is rvalue here. More e.g. x+y, return type of functions etc. rvalue reference: int&& x = 10; rvalue can be assigned to rvalue reference.
rvalue references allow binding to temporary objects, enabling move semantics where resources are transferred instead of copied.

```
```
int x = 10;   // x is lvalue and 10 is rvalue
int& y = x;   // y is lvalue reference and x is still lvalue
const int& y = 10; // rvalue is assigned to lvalue reference using const keyword
int&& y = 10; // rvalue is assigned to rvalue reference.
int a = b+c;    // b+c itself does not hold any identity and address hence rvalue
```
``````

lvalue → preserve
rvalue → reuse (move)
