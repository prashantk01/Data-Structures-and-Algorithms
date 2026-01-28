#include<iostream>
#include<thread>

#define targetCount 400000
int counter = 0; // global shared resource among all the threads

void function1(){
    int local_counter = 0;
    for(int i = 0; i<targetCount; i++){
        counter++; // critical section 
        local_counter++;
    }
    std::cout<<"Local counter value in function1: "<<local_counter<<std::endl;
}

void function2(){
    int local_counter = 0;
    for(int i=0; i<targetCount; i++){
        counter++; // critical section
        local_counter++;
    }
    std::cout<<"Local counter value in function1: "<<local_counter<<std::endl;
}


int main(){
    std::thread t1(function1);
    std::thread t2(function2);
    t1.join();
    t2.join();

    // expectation for this shared counter is to be 800000 after both threads complete their execution
    // but it won't happen because both threads updating same resource without synchronization
    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
