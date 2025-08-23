#include<bits/stdc++.h>
#include<thread>
#include<mutex>


using namespace std;
using namespace this_thread;

mutex mtx1, mtx2; // two mutexes for deadlock demonstration

void task1(int id){
    cout << "Task 1 trying to lock mtx1" << endl;
    mtx1.lock();
    cout << "Task 1 locked mtx1" << endl;
    sleep_for(chrono::milliseconds(100)); // simulate some work
    cout << "Task 1 trying to lock mtx2" << endl;
    mtx2.lock();
    cout << "Task 1 locked mtx2" << endl;

    // critical section
    cout << "Task 1 in critical section" << endl;

    mtx2.unlock();
    mtx1.unlock();
    cout << "Task 1 released locks" << endl;
}

void task2(int id){
    cout << "Task 2 trying to lock mtx2" << endl;
    mtx2.lock();
    cout << "Task 2 locked mtx2" << endl;
    sleep_for(chrono::milliseconds(100)); // simulate some work
    cout << "Task 2 trying to lock mtx1" << endl;
    mtx1.lock();
    cout << "Task 2 locked mtx1" << endl;

    // critical section
    cout << "Task 2 in critical section" << endl;

    mtx1.unlock();
    mtx2.unlock();
    cout << "Task 2 released locks" << endl;
}

void job1(int id){
    cout << "Job 1 trying to lock mtx1 and mtx2" << endl;
    lock(mtx1, mtx2); // lock both mutexes without deadlock
    cout << "Job 1 locked mtx1 and mtx2" << endl;

    // critical section
    cout << "Job 1 in critical section" << endl;

    mtx1.unlock();
    mtx2.unlock();
    cout << "Job 1 released locks" << endl;
}

void job2(int id){
    cout << "Job "<<id<<" trying to lock mtx 1 and mtx 2" << endl;
    lock(mtx1, mtx2); // lock both the mutex
    cout << "Job " << id << " has acuired lock on both mtx" << endl;
    cout << "Job " << id << " has entered into critical section" << endl;

    mtx1.unlock();
    mtx2.unlock();
    cout << "Job 2 released locks" << endl;

}

int main(){
    // thread t1(task1,1); // uncomment to enable deadlock condition
    // thread t2(task2, 2); // uncomment to enable deadlock condition

    thread t1(job1,1); // no deadlock condition
    thread t2(job2, 2); // no deadlock condition
    t1.join();
    t2.join();
    return 0;
}