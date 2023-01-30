#include "queue.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main (void) {
    //* Basic test of the queue with strings.
    Queue<std::string> stringqueue;
    stringqueue.enqueue("Hello");
    cout << stringqueue.peek() << endl;
    cout << stringqueue.dequeue() << endl << endl;

    //* This tests the queue with multiple items and the queuestate flag.
    Queue<int> intqueue;
    intqueue.enqueue(1);
    intqueue.enqueue(3);
    intqueue.enqueue(2);
    intqueue.enqueue(4);
    //* queuestate flag test.
    while (intqueue.queuestate() != 1) {
        cout << intqueue.peek() << ' ' << intqueue.dequeue() << endl;
    }
    cout << endl << "All tests passed.";
    return 0;
}