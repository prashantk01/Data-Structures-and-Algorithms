#include<bits/stdc++.h>
#include<thread>
#include<mutex>

using namespace std;
using namespace this_thread;
mutex mtx; // mutex for critical section

int counter = 0;
int targetCount = 100000;


int foo(int num)
{
    int lcounter = 0;
    for(int i=0; i<targetCount; i++){
        lock_guard<mutex> lock(mtx); // lock the critical section for current thread
        counter++;
        lcounter++;
    }
    cout<< "Thred Num: "<<num<<" Thread ID: " << get_id() << " Local Counter: " << lcounter << endl;
    return 0;
}
// this program will always give correct output as mutex is used to lock the critical section
// without mutex, the output will be unpredictable
// but this program will be slower as mutex is used to lock the critical section and other threads have to wait for the lock to be released
int main(){
    thread t1, t2;
    t1 = thread(foo,1);
    t2 = thread(foo,2);
    t1.join();
    t2.join();
    cout<< "Final Counter: " << counter << " Target Counter: " << 2*targetCount << endl;
    return 0;

}