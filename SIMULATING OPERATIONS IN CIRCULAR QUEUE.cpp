//Simulating Operations in Circular queue
#include <iostream>
using namespace std;

#define SIZE 5
int cqueue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % SIZE == front)
        cout << "Queue Overflow\n";
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        cqueue[rear] = val;
        cout << "Customer " << val << " added to queue.\n";
    }
}

void dequeue() {
    if (front == -1)
        cout << "Queue Underflow\n";
    else {
        cout << "Serving customer " << cqueue[front] << "...\n";
        if (front == rear)
            front = rear = -1; // Queue becomes empty
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1)
        cout << "Queue is empty.\n";
    else {
        cout << "Current Queue: ";
        int i = front;
        while (true) {
            cout << cqueue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
}

int main() {
    int choice, customerID = 200;

    do {
        cout << "\n--- Circular Queue Service Desk ---\n";
        cout << "1. Take Number (Enqueue)\n";
        cout << "2. Serve Customer (Dequeue)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: enqueue(customerID++); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
