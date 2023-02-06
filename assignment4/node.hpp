template <typename T>
// A double linked node, could be used for optimisation.
struct Node {
    T data;
    Node *next = nullptr;
    Node *before = nullptr;
};