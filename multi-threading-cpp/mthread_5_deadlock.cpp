#include<iostream>
#include<thread>
#include<mutex>


std::mutex mtx1; // mutex 1 
std::mutex mtx2; // mutex 2

void task1(int id){
    std::cout << "Task 1 trying to lock mtx1" << std::endl;
    mtx1.lock();
    std::cout << "Task 1 locked mtx1" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate some work
    std::cout << "Task 1 trying to lock mtx2" << std::endl;
    mtx2.lock();
    std::cout << "Task 1 locked mtx2" << std::endl;
    // critical section
    std::cout << "Task 1 in critical section" << std::endl;
    mtx2.unlock();
    mtx1.unlock();
    std::cout << "Task 1 released locks" << std::endl;
}

void task2(int id){
    std::cout << "Task 2 trying to lock mtx2" << std::endl;
    mtx2.lock();
    std::cout << "Task 2 locked mtx2" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate some work
    std::cout << "Task 2 trying to lock mtx1" << std::endl;
    mtx1.lock();
    std::cout << "Task 2 locked mtx1" << std::endl;
    // critical section
    std::cout << "Task 2 in critical section" << std::endl;
    mtx1.unlock();
    mtx2.unlock();
    std::cout << "Task 2 released locks" << std::endl;
}

void job1(int id){
    std::cout << "Job 1 trying to lock mtx1 and mtx2" << std::endl;
    lock(mtx1, mtx2); // lock both mutexes without deadlock
    std::cout << "Job 1 locked mtx1 and mtx2" << std::endl;
    // critical section
    std::cout << "Job 1 in critical section" << std::endl;
    mtx1.unlock();
    mtx2.unlock();
    std::cout << "Job 1 released locks" << std::endl;
}

void job2(int id){
    std::cout << "Job "<<id<<" trying to lock mtx 1 and mtx 2" << std::endl;
    lock(mtx1, mtx2); // lock both the mutex
    std::cout << "Job " << id << " has acuired lock on both mtx" << std::endl;
    std::cout << "Job " << id << " has entered into critical section" << std::endl;
    mtx1.unlock();
    mtx2.unlock();
    std::cout << "Job 2 released locks" << std::endl;
}

int main(){
    // std::thread t1(task1,1); // uncomment to enable deadlock condition
    // std::thread t2(task2, 2); // uncomment to enable deadlock condition

    std::thread t1(job1,1); // no deadlock condition
    std::thread t2(job2, 2); // no deadlock condition
    t1.join();
    t2.join();
    return 0;
}