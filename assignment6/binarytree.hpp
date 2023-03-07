#include <stdexcept>
#include "binarynode.hpp"
/*
This is a simple binary tree class that is barely functional.
It has the following available functions:
 -addvalue(int value)
 -findvalue(int value)
 -sizeoftree()
 -removevalue(int value)
*/
class binarytree {
    public:
        binarytree() {
            root = nullptr;
        }
        ~binarytree() {
            while (root != nullptr) removevalue(root->value);
        }
        // This function adds the specified value to the binary tree.
        void addvalue(int value) {
            binarynode* newnode = new binarynode;
            newnode->value = value;
            if (root == nullptr) {
                root = newnode;
            } else {
                addhelper(newnode, root);
            }
        }
        // This function finds if there is a value inside the binary tree, if it is not it throws std::domain_error
        int findvalue(int value) {
            return valuelocatehelper(value, root);
        }
        // This function uses a post order traversal to find the size of the binary tree.
        int sizeoftree(void) {
            return sizehelper(root);
        }
        // This function removes the specified value from the binary tree.
        bool removevalue(int value) {
            return removevaluehelper(value, root, root);
        }
    private:
        binarynode* root;
        // A helper function called by addvalue() it recursively places the new node. Or deletes it if it already exists.
        void addhelper(binarynode* newnode, binarynode* previousnode) {
            if (previousnode->value == newnode->value) {
                delete newnode;
            }
            if (newnode->value < previousnode->value) {
                if (previousnode->left == nullptr) {
                    previousnode->left = newnode;
                } else {
                    addhelper(newnode, previousnode->left);
                }
            }
             if (newnode->value >= previousnode->value) {
                if (previousnode->right == nullptr) {
                    previousnode->right = newnode;
                } else {
                    addhelper(newnode, previousnode->right);
                }
            }
        }
        // A helper function called by findvalue() it recursively checks to see if the value is in the tree. If it isn't it throws std::domain_error.
        int valuelocatehelper(int value, binarynode* node) {
            if (node->value == value) {
                return value;
            } else if ((value < node->value) && (node->left != nullptr)) {
                return valuelocatehelper (value, node->left);
            } else if ((value > node->value) && (node->right != nullptr)) {
                return valuelocatehelper(value, node->right);
            } else {
                throw std::domain_error("Value does not exist in list.");
            }
        }
        // A helper for sizeoftree() which recursively finds the size of the tree using a post-order traversal.
        int sizehelper(binarynode* node) {
            int size = 0;
            if (node->left != nullptr) {
                size = size + sizehelper(node->left);
            }
            if (node->right != nullptr) {
                size = size + sizehelper(node->right);
            }
            return size + 1;
        }
        // A helper for removevalue() it locates the value and processes the necessary steps for removing it.
        bool removevaluehelper(int value, binarynode* node, binarynode* parent) {
            if ((value < node->value) && (node->left != nullptr)) {
                return removevaluehelper(value, node->left, node);
            } else if ((value > node->value) && (node->right != nullptr)) {
                return removevaluehelper(value, node->right, node);
            } else if (node->value == value) {
                if ((node->left != nullptr) && (node->right != nullptr)) {
                    node->value = successorfinder(node->right, node);
                } else if (node->left != nullptr) {
                    binarynode* deletednode = node->left;
                    node->value = node->left->value;
                    node->right = node->left->right;
                    node->left = node->left->left;
                    delete deletednode;
                } else if (node->right != nullptr) {
                    binarynode* deletednode = node->right;
                    node->value = node->right->value;
                    node->left = node->right->left;
                    node->right = node->right->right;
                    delete deletednode;
                } else {
                    bool is_root = 0;
                    if (parent == node) is_root = 1;
                    if (parent->left == node && is_root == 0) parent->left = nullptr;
                    else if (parent->right == node && is_root == 0) parent->right = nullptr;
                    delete node;
                    if (is_root == 1) root = nullptr;
                }
                return 1;
            } else {
                return 0;
            }
        }
        // A helper for removevaluehelper() it finds the successor for the specified node and deletes it refrence from its parents.
        int successorfinder(binarynode* node, binarynode* parentnode) {
            if (node->left != nullptr) {
                return successorfinder(node->left, node);
            } else {
                int newvalue = node->value;
                if (node->right != nullptr) {
                    binarynode* deletednode = node;
                    node = node->right;
                    delete deletednode;
                } else {
                    if (parentnode->left == node) {
                        parentnode->left = nullptr;
                    } else {
                        parentnode->right = nullptr;
                    }
                    delete node;
                }
            return newvalue;
            }
        }
};