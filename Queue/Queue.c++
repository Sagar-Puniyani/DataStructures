#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return arr[rear];
    }

    int getSize() {
        return size;
    }
};

int main() {
    CircularQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << "Front: " << queue.getFront() << endl;
    cout << "Rear: " << queue.getRear() << endl;
    cout << "Size: " << queue.getSize() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "Front: " << queue.getFront() << endl;
    cout << "Rear: " << queue.getRear() << endl;
    cout << "Size: " << queue.getSize() << endl;

    return 0;
}