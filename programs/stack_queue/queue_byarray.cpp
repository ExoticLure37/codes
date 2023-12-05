#include <iostream>
using namespace std;
const int MAX_SIZE = 100; 
int arr[MAX_SIZE]; 
int front=-1, rear=-1.;          
void enqueue(int element) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue is full " << element << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    arr[rear] = element;
}
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1; 
    }
    int element = arr[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return element;
}
bool isEmpty() {
    return front == -1;
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Dequeued element: " << dequeue() << endl;
    cout << "Dequeued element: " << dequeue() << endl;
    return 0;
}
