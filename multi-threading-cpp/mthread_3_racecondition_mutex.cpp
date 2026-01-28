#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx; 
// mutual exclusion lock to protect critical section
// mutext works on os level locking mechanism - heavy weight locking mechanism
// risky in terms of deadlocks if not used properly such as code crashed before unlocking the mutex or exception occurred
// very slow as compared to atomic operations or guard locks

int counter = 0; // global shared resource among all the threads
#define targetcount 400000
// this program will always give correct output as mutex is used to lock the critical section

void function1(){
    int local_counter = 0;
    for(int i=0; i<targetcount; i++){
        local_counter++;
        mtx.lock(); // lock the critical section
        counter++; // critical section
        mtx.unlock(); // unlock the critical section
    }
    std::cout<<"local counter for thread 1: "<<local_counter<<std::endl;
}

// function 2 is implemented using lock_guard to avoid manual locking and unlocking of mutex
// lock_guard follows RAII principle - resource acquisition is initialization
// when lock_guard object is created it locks the mutex and when it goes out of scope it automatically unlocks the mutex
// it uses constructor and destructor to manage the lock and unlock of mutex
void function2(){
    int local_counter = 0;
    for(int i=0; i<targetcount; i++){
        local_counter++;
        std::lock_guard<std::mutex> lock(mtx); // lock the critical section
        counter++; // critical section
    }
    std::cout<<"local counter for thread 2: "<<local_counter<<std::endl;
}

int main(){
    std::thread t1(function1);
    std::thread t2(function2);
    t1.join();
    t2.join();
    std::cout<< "Final Counter: " << counter << " Target Counter: " << 2*targetcount << std::endl;
    return 0;
}