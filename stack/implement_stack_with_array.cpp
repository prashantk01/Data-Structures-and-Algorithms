#include<iostream>
using namespace std;

class stack {
    public: 
    int capacity;
    int *array;
    int topv;

    // para constructor inirializing stack parameters 
    stack (int cap){
        topv = -1;
        capacity = cap;
        array = new int [cap];
    }
    void pop(){
       if(topv<0){
           cout << "stack is empty, can't pop";
           return;
       }
       topv--;
    }
    int top() {
        cout << " top element is: " << array[topv];
        return array[topv];
    }
    void push(int val){
        if(topv==capacity-1){
            cout << "stack is full, can't insert";
            return;
        }
        array[++topv] = val;
    }
    void printStack(){
        cout << "stack at this position is [top]: ";
        for (int i = topv; i >= 0;i--){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};



int main(){
    stack s(10);
    s.push(4);
    s.push(6);
    s.push(7);
    s.top();
    s.printStack();
    s.top();
    s.pop();
    s.top();
    s.printStack();
    s.pop();
    s.printStack();
    s.pop();
    s.pop();
    return 0;
}