 #include<iostream>
 class TestClass{
    private:  // by default private in class
        int data;
    public:
        TestClass(){}  // default constructor
        void setData(int val){ // member function to set data
            data = val;
        }
        int getData(){  // member function to get data
            return data;
        }
};

int main(){
    TestClass obj; // STACK object creation, no need to use delete keyword
    obj.setData(10);
    std::cout<<"Data is: "<<obj.getData()<<std::endl;
    TestClass* ptr = new TestClass(); // HEAP object creation, need to use delete keyword
    ptr->setData(20);
    std::cout<<"Data is: "<<ptr->getData()<<std::endl;
    delete ptr; // free the heap memory
    return 0;
}