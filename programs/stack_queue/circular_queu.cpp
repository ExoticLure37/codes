#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int arr[MAX_SIZE]; 
int front, rear;   
int size;          
bool isEmpty() {
    return size == 0;
}

bool isFull() {
    return size == MAX_SIZE;
}
void enqueue(int element) {
    if (isFull()) {
        cout << "Circular queue is full" << element << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    arr[rear] = element;
    size++;
}
int dequeue() {
    if (isEmpty()) {
        cout << "Circular queue is empty." << endl;
        return -1; 
    }
    int element = arr[front];
    if (front == rear) {
        front = rear = -1;
    } else {
       front = (front + 1) % MAX_SIZE;
    }
    size--;
    return element;
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Dequeued element: " << dequeue() << endl;
    cout << "Dequeued element: " << dequeue() << endl;
    return 0;
}
