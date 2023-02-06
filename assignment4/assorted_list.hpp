#include "node.hpp"
template <typename T>

class assorted_list
{
private:
    Node<T> *head;
    Node<T> *tail;
    int length;
public:
    // Contructor for the assorted_list class
    assorted_list(/* args */) {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    // Deconstructor for the assorted_list class
    ~assorted_list() {
        while (head != nullptr) {
            remove(0);
        }
    }
    // this function inserts a node with a specified value BEFORE the specified index.
    void add(int index, T value) {
        if (index < 0) index = 0;
        else if (index > length) index = length;
        Node<T> *newnode = new Node<T>;
        newnode->data = value;
        if (index == 0) {
            if (head == nullptr) {
                head = newnode;
                tail = newnode;
            } else {
            head->before = newnode;
            newnode->next = head;
            head = newnode;
            }
        } else if (index == length) {
            tail->next = newnode;
            newnode->before = tail;
            tail = newnode;
        } else {
            Node<T> *displacednode = head;
            for (int i = 0; i < index; ++i) {
                displacednode = displacednode->next;
            }
            newnode->next = displacednode;
            newnode->before = displacednode->before;
            displacednode->before->next = newnode;
            displacednode->before = newnode;
        }
        ++length;
    }
    // this function removes the node at the specified index. Returns 1 or 0 to indicate failstate.
    bool remove (int index) {
        if (head == nullptr || index < 0 || index >= length) return 1;
        Node<T> *removednode;
        for (int i = 0; i < index; ++i) {
            removednode = removednode->next;
        }
        if (index == 0) {
            removednode = head;
            if (length > 1) {
            removednode->next->before = nullptr;
            head = removednode->next;
            }
            head = removednode->next;
            if (head == nullptr) tail = nullptr;
        } else if (index == (length-1)) {
            removednode = tail;
            removednode->before->next = nullptr;
            tail = removednode->before;
        } else {
            removednode = head;
            for (int i = 0; i < index; ++i) {
                removednode = removednode->next;
            }
            removednode->before->next = removednode->next;
            removednode->next->before = removednode->before;
        }
        delete removednode;
        --length;
        return 0;
    }
    // this function returns the value stored in the node at the specified index.
    T get (int index) {
        Node<T> *crawler = head;
        if (crawler == nullptr) throw std::out_of_range("Attempted to read from empty list.");
        if (index == (length-1)) crawler = tail;
        else {
            for (int i = 0; i < index; ++i) {
                crawler = crawler->next;
                if (crawler == nullptr) {
                    throw std::out_of_range("Index out of range.");
                }
            }
        }
        return crawler->data;
    }
    int len(void) {
        return length;
    }
};
