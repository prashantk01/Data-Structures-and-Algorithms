#include<iostream>
using namespace std;

class queue {
    int capacity;
    int *array;
    int rear;
    int front;

    public:
    // para constructor inirializing stack parameters 
    queue (int cap){
        front = rear = -1;
        capacity = cap;
        array = new int [cap];
    }
    void dequeue(){
       if(front==-1){
           cout << "queue is empty, can't dequeue" << endl;
           return;
       }
       else if(front==rear){
           front = rear = -1;
           return;
       }
       front = (front + 1) % capacity;
    }
    int top() {
        cout << "front element is: " << array[front]<<endl;
        return array[front];
    }
    void  enqueue(int val){
        if(front==(rear+1)%capacity){
            cout << "queue is full, can't enqueue" << endl;
            return;
        }
        if(front==-1)  //first element pushed to queue
            ++front;
        rear=(rear+1)%capacity;
        array[rear] = val;
    }
    void printQueue(){
        cout<< "queue at this position is " << endl;
        cout<<"[front]: ";
        int cnt = 0;
        for (int i = front; i <= rear; i = (i + 1) % capacity)
        {   
            cout << array[i] << " ";
        }
        cout << " :[rear]" << endl;
    }
};



int main(){ 
    // 4 5 6
    queue q(5);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.top();  // 4
    q.printQueue(); // 4 5 6
    q.dequeue();
    q.printQueue();  // 5 6
    q.dequeue();     
    q.printQueue();  // 6
    q.dequeue();     //
    q.dequeue();     // can't
    q.printQueue();
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.printQueue(); // 45678
    q.enqueue(9);   // can't
    q.dequeue();
    q.enqueue(9);
    q.printQueue(); //56789
    return 0;
}