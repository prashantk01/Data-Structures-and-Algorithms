#include<bits/stdc++.h>
#include<thread>

using namespace std;
using namespace this_thread;

int counter = 0; // shared resource
int targetCount = 100000;
void foo(int id)
{
    int lcounter = 0;
    for (int i = 0; i < targetCount; i++)
    {
        lcounter++;
        counter++;
    }
    cout<<"Thread No " << id << " Thread Id "<<get_id()<<" local counter: " << lcounter << endl;
}

int main(){
    thread t1(foo, 1);
    thread t2(foo, 2);
    t1.join();
    t2.join();

    // expectation for this shared counter is to be 20000 after both threads complete
    cout << "Final counter value: " << counter << endl;

    if(counter  == targetCount*2){
        cout << "lucky enough, no contenxt switching happened :), Try increasing target counter value"<<endl;
    }
    else{
        cout<<"Oh no! we have race condition :(, Try decreasing target counter value"<<endl;
    }
    return 0;
}
