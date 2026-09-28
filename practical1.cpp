#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
};

int main() {
    Stack s;
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');   // Convert character to integer
        } else {
            int op2 = s.pop();
            int op1 = s.pop();

            switch (ch) {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
                case '%':
                    s.push(op1 % op2);
                    break;
                default:
                    cout << "Invalid Operator!" << endl;
                    return 1;
            }
        }
    }

    cout << "Result = " << s.pop() << endl;

    return 0;
}
