#include <iostream>
using namespace std;
const int MAX_SIZE = 100; 
int arr[MAX_SIZE];
int top=-1;         
void push(int element) {
    if (top >= MAX_SIZE - 1) {
        cout << "Overflow " << endl;
        return;
    }
    arr[++top] = element;
}
int pop() {
    if (isEmpty()) {
        cout << "Underflow" << endl;
            return -1; 
        }
    return arr[top--];
}
bool isEmpty() {
    if(top==-1){
        return true;
    }
    else{return false;}
}
int peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return arr[top];
}
int main() {
    push(10);
    push(20);
    push(30);
    cout << "Top element: " << peek() << endl;

    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;

    return 0;
}
