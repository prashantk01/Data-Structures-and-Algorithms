#include <iostream>
using namespace std;

class Base
{
public:
    void show()
    {
        cout << "Single Base instance\n";
    }
};

// 'virtual' ensures that only ONE shared Base subobject
// is created in the final derived class (C)
class A : virtual public Base
{
};
class B : virtual public Base
{
};

// Diamond structure:
//        Base
//       /    \
//      A      B
//       \    /
//         C
class C : public A, public B
{
};

int main()
{
    C obj;

    obj.show();
    /*
        Output:
        Single Base instance

        Why?
        - Because A and B virtually inherit Base.
        - So C contains ONLY ONE Base object.
        - Therefore, no ambiguity in calling show().

        If 'virtual' was removed:
        - C would contain TWO Base subobjects.
        - obj.show() would cause compilation error (ambiguous).
    */
}