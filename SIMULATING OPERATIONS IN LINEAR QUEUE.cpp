//Simulating Operations in linear queue
#include <iostream>
using namespace std;

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1)
        cout << "Queue Overflow\n";
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
        cout << "Customer " << val << " added to queue.\n";
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        cout << "Queue Underflow\n";
    else {
        cout << "Serving customer " << queue[front] << "...\n";
        front++;
    }
}

void display() {
    cout << "\n--- QUEUE STATUS ---\n";
    if (front == -1 || front > rear)
        cout << "Queue is empty.\n";
    else {
        cout << "Customers in queue: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << "\nFront at position: " << front << ", Rear at position: " << rear << "\n";
    }


}

int main() {
    int choice, customerID = 35;

    do {
        cout << "\n SERVICE DESK MENU \n";
        cout << "1. Please take a Number \n";
        cout << "2. Serve Customer \n";
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
