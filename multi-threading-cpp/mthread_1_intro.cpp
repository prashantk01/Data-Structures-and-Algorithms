#include<iostream>
#include<thread>

// Concurrency - When system has single core and multiple threads executing one by one - context switching
// Parallelism - When system has multiple cores and multiple threads executing simultaneously

// Multitasking - Single core executing multiple tasks by time slicing
// Multiprocessing - Multiple cores executing multiple tasks simultaneously

// explore this code directory in sequence 1,2,3,4,5..6 for better understanding of multithreading concepts 
void function(){
    std::cout<<"Thread ID: "<<std::this_thread::get_id()<<std::endl;
}

int main()
{
    int cpu_core = std::thread::hardware_concurrency();
    std::cout << "Number of CPU cores available: " << cpu_core << std::endl;
    std::thread t1(function);
    t1.join();
    return 0;
}
