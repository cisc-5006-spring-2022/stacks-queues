#include <iostream>
#include "ArrayQue.h"

using namespace std;

int main() {
    ArrayQue<int> q = ArrayQue<int>(20);

    for(int i = 0; i < 20; i++) {
        q.Enqueue(i);
    }

    for(int i = 0; i < 10; i++) {
        q.Dequeue();
    }

    for(int i = 0; i < 10; i++) {
        q.Enqueue(-100);
    }

    while(!q.IsEmpty()) {
        cout << q.Dequeue() << endl;
    }
}