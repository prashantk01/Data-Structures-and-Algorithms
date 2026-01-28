#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<queue>

#define MAX_SIZE 10
std::mutex mtx;
std::condition_variable pcv;
std::condition_variable ccv;
std::queue<int> q;

void producer(){
    for(int i=0; i<2*MAX_SIZE; i++){
        // conditional lock - unlock thread when queue size is less than max size
        std::unique_lock<std::mutex> lock(mtx);
        pcv.wait(lock,[]{return q.size()<MAX_SIZE;});
        q.push(i);
        std::cout<<"Produced: "<<i<<std::endl;
        ccv.notify_one(); // notify consumer thread
    }
}

void consumer(){
    for(int i=0; i<2*MAX_SIZE; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // conditional lock - unlock thread when queue size is greater than 0
        std::unique_lock<std::mutex> lock(mtx);
        ccv.wait(lock,[]{return q.size()>0;});
        std::cout<<"Consumed: "<<q.front()<<std::endl;
        q.pop();
        pcv.notify_one(); // notify producer thread
    }
}

int main(){
    std::thread pthread(producer);
    std::thread cthread(consumer);
    pthread.join();
    cthread.join();
    return 0;
}