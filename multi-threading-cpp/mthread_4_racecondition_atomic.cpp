#include<iostream>
#include<thread>
#include<atomic>

std::atomic<int> counter(0); 
// global shared resource among all the threads - atomic variable means operations on this variable are atomic in nature
// faster than mutex as it works on hardware level locking mechanism - lock free programming
#define targetcount 400000

void function1(){
    int local_counter = 0;
    for(int i=0; i<targetcount; i++){
        local_counter++;
        counter++; // atomic operation
    }
    std::cout<<"local counter for thread 1: "<<local_counter<<std::endl;
}

void function2(){
    int local_counter = 0;
    for(int i=0; i<targetcount; i++){
        local_counter++;
        counter++; // atomic operation
    }
    std::cout<<"local counter for thread 2: "<<local_counter<<std::endl;
}

int main(){
    std::thread t1(function1);
    std::thread t2(function2);
    t1.join();
    t2.join();
    std::cout<<"final counter: "<< counter<<std::endl;
    return 0;
}