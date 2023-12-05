#include <iostream>
#include <queue>
using namespace std;
queue<int> q1, q2; 
void push(int element) {
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(element);
    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
}
int pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot pop." << endl;
        return -1;
    }
    int element = q1.front();
    q1.pop();
    return element;
}
    bool isEmpty() {
        return q1.empty();
    }

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;

    return 0;
}
