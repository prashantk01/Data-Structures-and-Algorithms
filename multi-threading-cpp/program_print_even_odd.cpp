#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>

std::mutex mtx;
std::condition_variable cv;
int counter  = 0;
void printOdd(){
    while(1){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[]{
            return counter%2 != 0 || counter > 10;
        });
        if(counter>10){
            cv.notify_one();
            break;
        }
        std::cout<<counter <<" ";
        counter++;
        cv.notify_one();
    }
}
 
void printEven(){
    while(1){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[]{
            return counter%2 == 0 || counter > 10;
        });
        if(counter>10){
            cv.notify_one();
            break;
        }
        std::cout<<counter <<" ";
        counter++;
        cv.notify_one(); 
    }
}
 
int main(){
    std::thread t1(printEven);
    std::thread t2(printOdd);
    t1.join();
    t2.join();
    return 0;
}