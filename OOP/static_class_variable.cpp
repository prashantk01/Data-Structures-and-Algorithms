#include<iostream>
class test {
    private:
       inline static int a =0; // static variable, shared among all objects of the class
    public:
        test(){
            a++; // incrementing static variable in constructor
        }
        int getter(){
            return a;
        }
        void setter(int val){
            a = val;
        }
};

// int test::a; // initializing static variable outside the class

int main(){
    test t1;
    std::cout<<"Value of a after creating t1: "<<t1.getter()<<std::endl; // should print 1
    test t2;
    std::cout<<"Value of a after creating t2: "<<t2.getter()<<std::endl; // should print 2
    t2.setter(10); // setting static variable a to 10 using t2
    std::cout<<"Value of a after setting a to 10 using t2: "<<t1.getter()<<std::endl; // should print 10
    std::cout<<"Value of a after setting a to 10 using t2: "<<t2.getter()<<std::endl; // should print 10
    test t3;
    std::cout<<"Value of a after creating t3: "<<t3.getter()<<std::endl; // should print 11
    // std::cout<<"Value of a using literal access: "<< test::a <<std::endl; // accessing static variable using class name, should print 11
    return 0;
}

// Static class variables are shared among all objects of the class, only one copy exists.
// They are initialized only once before main class and retain their value across all instances of the class.
// Static variables can be accessed using the class name as well: test::a but a should be public for that.
// Static variables must be defined outside the class definition
// Inline static variables can be initialized inside the class definition itself (C++17 and later).