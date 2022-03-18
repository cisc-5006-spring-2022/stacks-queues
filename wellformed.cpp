#include "Stack.h"
#include "LinkedStack.h"

#include <iostream>
#include <string>

using namespace std;

bool isOpen(char c) {
    return (c == '(' || c == '{');
}

bool isClosed(char c) {
    return (c == ')' || c == '}');
}

int main() {
    string expression = "{{{(z)}}}";
    LinkedStack<char> s;

    try {
        for(int i = 0; i < expression.size(); i++) {
            cout << expression[i] << endl;

            if (isOpen(expression[i])) {
                s.Push(expression[i]);
            } else if (isClosed(expression[i])) {
                char top = s.Top();

                if (
                    (top == '(' && expression[i] == ')') ||
                    (top == '{' && expression[i] == '}')
                ) {
                    // Expression is well-formed so far
                    s.Pop();
                } else {
                    cout << "Ill formed!" << endl;
                    break;
                }
                cout << "Top: " << top << endl;
            }
        }
    } catch(EmptyStack e) {
        cout << "Ill-formed!" << endl;
        return 0;
    }

    if (!s.IsEmpty()) {
        cout << "Ill-formed!" << endl;
        return 0;
    }

    cout << "Well-formed" << endl;
}