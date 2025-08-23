#include<bits/stdc++.h>
#include<thread>
#include<atomic>

using namespace std;
using namespace this_thread;
atomic<int> counter(0); // atomic variable for critical section
int targetCount = 100000;

void foo(int num)
{
    int lcounter = 0;
    for(int i=0; i<targetCount; i++){
        counter++; // atomic operation, no need to lock the critical section
        lcounter++;
    }
    cout<< "Thred Num: "<<num<<" Thread ID: " << get_id() << " Local Counter: " << lcounter << endl;
}

// this program will always give correct output as atomic variable is used for critical section
// without atomic variable, the output will be unpredictable
// this program will be faster as atomic variable is used for critical section and other threads do not have to wait for the lock to be released
int main(){
    thread t1, t2;
    t1 = thread(foo, 1);
    t2 = thread(foo, 2);
    t1.join();
    t2.join();
    cout<< "Final Counter: " << counter.load() << " Target Counter: " << targetCount*2 << endl;
    return 0;
}