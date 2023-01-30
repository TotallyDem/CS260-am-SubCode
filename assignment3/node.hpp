// This file is formatted as a .hpp file because of templating.
template <typename T>
// Basic node class for use in linked lists.
struct Node {
    T value;
    Node *next = nullptr;
};