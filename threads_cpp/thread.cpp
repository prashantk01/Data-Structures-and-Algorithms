#include<bits/stdc++.h>
#include<thread>

using namespace std;
using namespace this_thread;



void display(int id){
    cout << id<< " : Hi I am print function invoked by Thread ID: " << get_id() << endl;
}


int main()
{
    cout<< " Master Thread started, Thread ID: " << get_id() << endl;
    display(1);  // master thread is the thread that creates, manages, and synchronizes other threads.
    thread t1(display,2); // run parallelly to master thread
    thread t2(display,3); // run parallelly to master thread and t1 thread
    cout<< " Master Thread ended, Thread ID: " << get_id() << endl;
    t1.join(); // master thread waits for t1 to complete
    t2.join(); // master thread waits for t2 to complete
    thread t3(display, 4); // run parallelly to master thread
    t3.detach(); // t3 thread runs independently, master thread does not wait for t3 to complete
    sleep_for(chrono::seconds(1)); // sleep for 1 second to allow t3 to complete
    cout<< " Main Thread ended, Thread ID: " << get_id() << endl;
    return 0;
}
