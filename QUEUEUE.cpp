// witch.tape
#include <iostream>
#include <string>
using namespace std;

struct Document {
    string filename;
    int priority; // 1 = Guest, 2 = Admin, 3 = Manager, 4 = Director
};

template <typename T, int MAX_SIZE>
class PriorityQueue {
private:
    T arr[MAX_SIZE];
    int count;

public:
    PriorityQueue() : count(0) {}

    bool IsEmpty() const {
        return count == 0;
    }

    bool IsFull() const {
        return count == MAX_SIZE;
    }

    void Enqueue(const T& item) {
        if (IsFull()) {
            cout << "Queue is full! Cannot add more documents.\n";
            return;
        }

        int i = count - 1;

        // shift elements to maintain highest-priority-first
        while (i >= 0 && arr[i].priority < item.priority) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = item;
        count++;
        cout << "Document added to queue.\n";
    }

    T Dequeue() {
        if (IsEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        T item = arr[0];
        for (int i = 1; i < count; i++) {
            arr[i - 1] = arr[i];
        }
        count--;
        return item;
    }

    void PrintQueue() const {
        if (IsEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "\nDocuments in queue:\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << arr[i].filename << " (priority " << arr[i].priority << ")\n";
        }
    }
};

int main() {
    PriorityQueue<Document, 10> printer; // max 10 docs
    int choice;

    do {
        cout << "\n===== PRINTER QUEUE MENU =====\n";
        cout << "1. Add document\n";
        cout << "2. Print document\n";
        cout << "3. Show queue\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Document d;
            cout << "Enter file name: ";
            cin >> d.filename;
            cout << "Select role:\n";
            cout << "1 - Guest\n2 - Administrator\n3 - Manager\n4 - Director\n";
            cout << "Priority: ";
            cin >> d.priority;
            printer.Enqueue(d);
            break;
        }
        case 2:
            try {
                Document d = printer.Dequeue();
                cout << "Printing document: " << d.filename << " (priority " << d.priority << ")\n";
            }
            catch (...) {
                cout << "Printer queue is empty.\n";
            }
            break;
        case 3:
            printer.PrintQueue();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
