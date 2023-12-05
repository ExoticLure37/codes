#include <iostream>
#include <queue>
using namespace std;
queue<int> q1, q2;
void push(int element) {
    if (q1.empty()) {
        q2.push(element);
    } else {
        q1.push(element);
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return -1;
        }
    queue<int>& nonEmptyQueue = q1.empty() ? q2 : q1;
    queue<int>& emptyQueue = q1.empty() ? q1 : q2;
    while (nonEmptyQueue.size() > 1) {
        emptyQueue.push(nonEmptyQueue.front());
        nonEmptyQueue.pop();
    }
    int element = nonEmptyQueue.front();
    nonEmptyQueue.pop();
    return element;
}

bool isEmpty() {
    return q1.empty() && q2.empty();
}


int main() {
    push(10);
    push(20);
    push(30);
    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;
    return 0;
}
