#include "LinkedStack.h"
#include "ArrayQue.h"

#include <iostream>

using namespace std;

int main() {
    LinkedStack<char> s = LinkedStack<char>();
    ArrayQue<char> q = ArrayQue<char>(100);

    string str = "tacocatt";

    for (char c: str) {
        s.Push(c);
        q.Enqueue(c);
    }

    for (int i = 0; i < str.length(); i++) {
        char c1 = s.Top();
        s.Pop();
        char c2 = q.Dequeue();

        if (c1 != c2) {
            cout << "Not a palindrome" << endl;
            break;
        }
    }

    cout << "Palindrome!" << endl;
}