#include "LinkedStack.h"
#include "ArrayQue.h"

#include <iostream>

using namespace std;

bool is_palindrome(string str) {
    LinkedStack<char> s = LinkedStack<char>();
    ArrayQue<char> q = ArrayQue<char>(100);

    for (char c: str) {
        s.Push(c);
        q.Enqueue(c);
    }

    bool is_palindrome = true;

    for (int i = 0; i < str.length(); i++) {
        char c1 = s.Top();
        s.Pop();
        char c2 = q.Dequeue();

        if (c1 != c2) {
            return false;
        }
    }
    return true;
}
int main() {
    if (is_palindrome("tacocat")) {
        cout << "tacocat is a palindrome" << endl;
    } else {
        cout << "tacocat is not a palindrome" << endl;
    }

    if (is_palindrome("hello")) {
        cout << "hello is a palindrome" << endl;
    } else {
        cout << "hello is not a palindrome" << endl;
    }
}