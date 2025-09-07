#include<iostream>
class test{
    private:
        int data; 
        inline static int sdata; // static class variable
    public:
        test(){
            sdata++;
            data++;
        }
        static int getStaticData(){
            // sdata = data + sdata; // accessing non-static member data inside static member function is not allowed
            return sdata;
        }
        int getData(){
            data = data + sdata;
            return data;
        }
};

int main(){
    test t1;
    std::cout<<"static data after creating t1: "<<t1.getStaticData()<<std::endl; // should print 1
    test t2;
    std::cout<<"static data after creating t2: "<<t2.getStaticData()<<std::endl; // should print 2
    test t3;
    std::cout<<"static data after creating t3: "<<t3.getStaticData()<<std::endl; // should print 3
    std::cout<<"static data using literal access: "<< test::getStaticData() <<std::endl; // accessing static member function using class name, should print 3
    std::cout<<"data of t3: "<<t3.getData()<<std::endl; // should print 4 (data=1 + sdata=3)
    return 0;
}

// Static class methods can be called using the class name as well: test::getStaticData()
// Static class methods can only access static class variables and other static class methods.
// They cannot access non-static class variables or methods because they do not have a "this" pointer.
// Static class methods do not require an object of the class to be called.