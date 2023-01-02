#include<bits/stdc++.h>
using namespace std;

#define n 100

class Queue {
    int arr[n];
    int front;
    int rear;
    public:
    Queue() {
        front = -1;
        rear = -1;
    }
    void insert(int x) {
        if(rear == n-1) {
            cout << "Queue Overflow\n";
        }
        else {
            if(front == -1) {
                front ++;
            }
            rear = rear + 1;
            arr[rear] = x;
        }
    }
    int Delete() {
        int item;
        if(rear == -1 and front == -1) {
            cout << "Queue Empty\n";
        }
        else if(front == rear) {
            item = arr[front];
            front = -1;
            rear = -1;
        }
        else {
            item = arr[front];
            front += 1;
        }
        return front;
    }
    void display() {
        cout << "\n----------------DISPLAY------------------\n";
        cout << "Front: " << front << endl;
        cout << "Rear: " << rear << endl;
        if(front == -1 and rear == -1) {
            cout << "Queue is Empty\n";
            return;
        }
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "-------------------------------------------\n\n";
    }
};

int main() {
    Queue q;
    cout << "\n----------PROGRAM FOR SIMULATING JOB QUEUE--------------\n";
    cout << "\nMENU:\n1. Insert Job\n2. Delete Job\n3. Display\n4. Exit\n";
    do {
        cout << "\nEnter choice: ";
        int choice;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "\n--------------INSERT----------------\n";
                cout << "Enter value: ";
                int x;
                cin >> x;
                q.insert(x);
                cout << "\n-------------------------------------\n";
                break;
            case 2:
                cout << "\n---------------DELETE----------------\n";
                q.Delete();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "\n------------EXITING-------------\n";
                exit(0);
        }
    }
    while(true);
}



