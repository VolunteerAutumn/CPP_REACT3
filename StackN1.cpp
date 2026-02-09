#include <iostream>
#include <locale>
// This is for le aesthetika
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

/* ================= STACK CLASS ================= */

class Stack {
private:
    char* arr;
    int capacity;
    int top;

public:
    Stack() : arr(nullptr), capacity(0), top(-1) {}

    Stack(int cap) : capacity(cap), top(-1) {
        arr = new char[capacity];
        for (int i = 0; i < capacity; i++)
            arr[i] = '\0';
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
        if (IsFull()) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = c;
        cout << "Pushed '" << c << "'\n";
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Stack underflow!\n";
            return;
        }
        cout << "Popped '" << arr[top] << "'\n";
        arr[top--] = '\0';
    }

    void Count() {
        cout << "Count: " << (top + 1) << endl;
    }

    void Clear() {
        for (int i = 0; i <= top; i++)
            arr[i] = '\0';
        top = -1;
        cout << "Stack cleared\n";
    }

    char Get(int index) {
        if (index < 0 || index > top) {
            cout << "Index out of bounds\n";
            return;
        }
        return arr[index];
    }

    void Print() {
        cout << "Stack (bottom → top): ";
        if (IsEmpty()) {
            cout << "[empty]\n";
            return;
        }
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

/* ================= UTILS ================= */

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pause() {
    cout << "\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

/* ================= MAIN ================= */

int main() {
    setlocale(LC_ALL, "");

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int capacity;
    cout << "Enter stack capacity: ";
    cin >> capacity;

    Stack s(capacity);
    int choice;
    char value;
    int index;

    do {
        ClearScreen();

        cout << "===== STACK MENU =====\n";
        cout << "1️  Push\n";
        cout << "2️  Pop\n";
        cout << "3️  Count\n";
        cout << "4️  Is Empty?\n";
        cout << "5️  Is Full?\n";
        cout << "6️  Clear Stack\n";
        cout << "7️  Get Element\n";
        cout << "8️  Print Stack\n";
        cout << "0️  Exit\n";
        cout << "Choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter char: ";
            cin >> value;
            s.Push(value);
            break;
        case 2:
            s.Pop();
            break;
        case 3:
            s.Count();
            break;
        case 4:
            cout << (s.IsEmpty() ? "Stack is EMPTY\n" : "Stack is NOT empty\n");
            break;
        case 5:
            cout << (s.IsFull() ? "Stack is FULL\n" : "Stack is NOT full\n");
            break;
        case 6:
            s.Clear();
            break;
        case 7:
            cout << "Enter index: ";
            cin >> index;
            cout << "The element on this index iiiiiis... " << s.Get(index) << "!!" << endl;
            break;
        case 8:
            s.Print();
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
			cout << "Invalid choice (much like your life choices \\j)\n";
        }

        if (choice != 0)
            Pause();

    } while (choice != 0);
}
