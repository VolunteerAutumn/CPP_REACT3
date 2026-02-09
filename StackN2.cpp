#include <iostream>
using namespace std;

class Stack {
private:
    char* arr;
    int capacity;
    int top;

    void Resize() {
        int newCapacity = capacity * 2;
        char* newArr = new char[newCapacity];

        for (int i = 0; i <= top; i++)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;

        cout << "📈 Stack resized to capacity " << capacity << endl;
    }

public:
    Stack(int cap = 4) {
        capacity = cap;
        top = -1;
        arr = new char[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == capacity - 1;
    }

    void Push(char c) {
        if (IsFull())
            Resize();

        arr[++top] = c;
        cout << "Pushed '" << c << "'\n";
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Stack underflow\n";
            return;
        }
        cout << "Popped '" << arr[top] << "'\n";
        top--;
    }

    void Count() {
        cout << "Count: " << (top + 1) << endl;
    }

    char Get(int index) {
        if (index < 0 || index > top) {
            cout << "Index out of bounds\n";
            return 0;
        }
        return arr[index];
    }

    void Print() {
        cout << "Stack (bottom -> top): ";
        if (IsEmpty()) {
            cout << "[empty]\n";
            return;
        }
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};


int main() {
    Stack s(2);

    s.Push('A');
    s.Push('B');
    s.Push('C');
    s.Push('D');

    s.Print();
    s.Count();

    s.Pop();
    s.Pop();

    s.Print();
}
