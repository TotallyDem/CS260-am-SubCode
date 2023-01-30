#include "node.hpp"
template <typename T>
/*
This class has the following methods:
 * enqueue(T value)
*/
class Queue {
    public:
        /*
        This function accepts a value and appends it to the end of the queue.
        If the queue is empty it starts the queue with the value.
        */
        void enqueue(T value) {
            if (queuehead != nullptr) {
                Node<T> *endqueue = queuehead;
                while (endqueue->next != nullptr) {
                    endqueue = endqueue->next;
                }
                Node<T> *newnode = new Node<T>;
                newnode->value = value;
                endqueue->next = newnode;
            } else {
                Node<T> *headnode = new Node<T>;
                headnode->value = value;
                queuehead = headnode;
            }
        }
        /*
        This function will remove the front of the queue and return its value.
        If the queue is empty this will result in undefined behavior.
        */
        T dequeue() {
            Node<T> *newhead = queuehead->next;
            T endvalue = queuehead->value;
            delete queuehead;
            queuehead = newhead;
            return endvalue;
        }
        /*
        This function will return the value at the head of the queue.
        If the queue is empty this will result in undefined behavior.
        */
        T peek() {
            return queuehead->value;
        }
        /*
        This function will return the state of the queue.
         - 1 if the queue is empty or 0 if the the queue is not.
        */
        int queuestate() {
            if (queuehead == nullptr) return 1;
            else return 0;
        }
        // Constructor for the Queue class.
        Queue() {
            queuehead = nullptr;
        }
        // Deconstructor for the queue class.
        ~Queue() {
            // Empties the queue to hopefully garuentee memory is freed.
            while (queuestate() == 0) {
                dequeue();
            }
        }
    private:
        Node<T> *queuehead;
};