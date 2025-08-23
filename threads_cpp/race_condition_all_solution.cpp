#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
using namespace std;
using namespace std::chrono;

mutex mtx;

// Common target count
const int targetCount = 1000000; // Increase for bigger impact
const int threadCount = 2;

// Approach 1: Race Condition (No Lock)
int counterRace = 0;
void fooRace(int num) {
    for (int i = 0; i < targetCount; i++) {
        counterRace++; // UNSAFE
    }
}

// Approach 2: Mutex on every increment (slow)
int counterMutex = 0;
void fooMutex(int num) {
    for (int i = 0; i < targetCount; i++) {
        lock_guard<mutex> lock(mtx);
        counterMutex++;
    }
}

// Approach 3: Optimized Mutex (fast)
int counterOptimized = 0;
void fooOptimizedMutex(int num) {
    int localCounter = 0;
    for (int i = 0; i < targetCount; i++) {
        localCounter++;
    }
    { // lock only once
        lock_guard<mutex> lock(mtx);
        counterOptimized += localCounter;
    }
}

// Approach 4: Atomic
atomic<int> counterAtomic(0);
void fooAtomic(int num) {
    for (int i = 0; i < targetCount; i++) {
        counterAtomic++;
    }
}

// Helper to measure time
template <typename Func>
void measure(const string& name, Func f) {
    auto start = high_resolution_clock::now();
    f();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << name << " took: " << duration << " ms" << endl<<endl;
}


// This program compares four approaches to handle race conditions in multithreading:
// 1. No synchronization
// 2. Mutex locking on every increment
// 3. Optimized mutex locking (lock once per thread)
// 4. Atomic operations
// It measures and prints the time taken and final counter values for each approach.
int main() {
    cout << "Comparing different thread synchronization approaches:\n";
    cout << "Target Count per thread: " << targetCount
         << ", Threads: " << threadCount << "\n\n";

    // 1. Race Condition
    measure("Race Condition (No Lock)", []() {
        counterRace = 0;
        thread t1(fooRace, 1);
        thread t2(fooRace, 2);
        t1.join(); t2.join();
        cout << "Final Counter: " << counterRace
             << " Expected: " << targetCount * threadCount << "\n";
    });

    // 2. Mutex on every increment
    measure("Mutex (Lock per increment)", []() {
        counterMutex = 0;
        thread t1(fooMutex, 1);
        thread t2(fooMutex, 2);
        t1.join(); t2.join();
        cout << "Final Counter: " << counterMutex
             << " Expected: " << targetCount * threadCount << "\n";
    });

    // 3. Optimized Mutex
    measure("Optimized Mutex (Lock once per thread)", []() {
        counterOptimized = 0;
        thread t1(fooOptimizedMutex, 1);
        thread t2(fooOptimizedMutex, 2);
        t1.join(); t2.join();
        cout << "Final Counter: " << counterOptimized
             << " Expected: " << targetCount * threadCount << "\n";
    });

    // 4. Atomic
    measure("Atomic (No Mutex)", []() {
        counterAtomic = 0;
        thread t1(fooAtomic, 1);
        thread t2(fooAtomic, 2);
        t1.join(); t2.join();
        cout << "Final Counter: " << counterAtomic
             << " Expected: " << targetCount * threadCount << "\n";
    });

    return 0;
}
