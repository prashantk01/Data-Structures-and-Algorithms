#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <condition_variable> // A condition variable allows threads to sleep without busy-waiting until a condition becomes true, and wake up efficiently when notified.
#include <queue>
#include <chrono>
using namespace std;


// Shared buffer and synchronization primitives
queue<int> buffer;              // Shared queue
const int BUFFER_SIZE = 5;      // Maximum capacity of buffer
mutex mtx;                      // Mutex for critical section
condition_variable cv_producer; // Producer waits if buffer is full
condition_variable cv_consumer; // Consumer waits if buffer is empty


// ---------------- Producer Function ----------------
void producer(int id, int items) {
    for (int i = 1; i <= items; i++) {
        // Acquire lock before modifying shared resource
        unique_lock<mutex> lock(mtx);

        // Wait until buffer has space
        cv_producer.wait(lock, [] 
                        { return buffer.size() < BUFFER_SIZE; });

        // Produce item and push into buffer
        buffer.push(i);
        cout << "[Producer " << id << "] Produced: " << i
             << " | Buffer size: " << buffer.size() << "\n";

        // Release lock before notifying to avoid waking thread unnecessarily
        lock.unlock();

        // Notify one consumer that buffer is not empty now
        cv_consumer.notify_one();

        // Simulate production delay
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// ---------------- Consumer Function ----------------
void consumer(int id, int items) {
    for (int i = 1; i <= items; i++) {
        // Acquire lock before accessing buffer
        unique_lock<mutex> lock(mtx);

        // Wait until buffer has at least one item
        cv_consumer.wait(lock, [] { return !buffer.empty(); });

        // Consume item from buffer
        int item = buffer.front();
        buffer.pop();
        cout << "\t[Consumer " << id << "] Consumed: " << item
             << " | Buffer size: " << buffer.size() << "\n";

        // Release lock before notifying
        lock.unlock();

        // Notify one producer that buffer has space now
        cv_producer.notify_one();

        // Simulate consumption delay
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

// ---------------- Main Function ----------------
int main() {
    int itemsPerProducer = 10; // Each producer will produce 10 items

    cout << "Starting Producer-Consumer Demo...\n\n";

    // Create two producers and two consumers
    thread p1(producer, 1, itemsPerProducer);
    thread p2(producer, 2, itemsPerProducer);
    thread c1(consumer, 1, itemsPerProducer);
    thread c2(consumer, 2, itemsPerProducer);

    // Wait for all threads to finish
    p1.join();
    p2.join();
    c1.join();
    c2.join();

    cout << "\nAll producers and consumers finished.\n";
    return 0;
}
