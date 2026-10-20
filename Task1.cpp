#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow!\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = token;
        cout << "Customer " << token << " added.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No customers waiting.\n";
            return;
        }

        cout << "Customer " << arr[front] << " is being served.\n";
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No customers waiting.\n";
            return;
        }

        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void count() {
        if (front == -1)
            cout << "Waiting customers: 0\n";
        else
            cout << "Waiting customers: " << rear - front + 1 << endl;
    }
};

int main() {
    Queue q;
    int choice, token;

    do {
        cout << "\n1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Customers\n";
        cout << "4. Count Customers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter token number: ";
                cin >> token;
                q.enqueue(token);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                q.count();
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
