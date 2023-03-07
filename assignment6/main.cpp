#include "binarytree.hpp"
#include <iostream>

int main (void) {
    binarytree TestTree;
    // Testing adding a new root.
    TestTree.addvalue(4);
    // Testing adding a node which goes to the 'left'
    TestTree.addvalue(3);
    // Testing adding a node which goes to the 'right'
    TestTree.addvalue(5);
    // Adding more nodes for removal testing later
    TestTree.addvalue(0);
    TestTree.addvalue(-1);
    TestTree.addvalue(-2);
    // See if nodes exists
    std::cout << TestTree.findvalue(4) << std::endl;
    std::cout << TestTree.findvalue(3) << std::endl;
    std::cout << TestTree.findvalue(5) << std::endl;
    std::cout << TestTree.findvalue(0) << std::endl;
    // Checking for value that does not exist in the list
    try {
        TestTree.findvalue(-20);
    } catch (std::domain_error& e) {
        std::cout << "-20 " << e.what() << std::endl;
    }
    // Trying my sizeoftree function which uses a post order traversal;
    std::cout << "My tree currently has " << TestTree.sizeoftree() << " nodes." << std::endl;
    // Trying out my removal function 
    std::cout << "Did 4 get removed? " << TestTree.removevalue(4) << std::endl;
    std::cout << "Did 5 get removed? " << TestTree.removevalue(5) << std::endl;
    std::cout << "Did -2 get removed? " << TestTree.removevalue(-2) << std::endl;
    std::cout << "Did 0 get removed? " << TestTree.removevalue(0) << std::endl;
    std::cout << "Did -1 get removed? " << TestTree.removevalue(-1) << std::endl;
    // Testing a value that does not exist
    std::cout << "Did -10 get removed? " << TestTree.removevalue(-10) << std::endl;
    TestTree.addvalue(7);
    std::cout << "Did 3 get removed? " << TestTree.removevalue(3) << std::endl;
    std::cout << "Did 7 get removed? " << TestTree.removevalue(7) << std::endl;
    return 0;
}
