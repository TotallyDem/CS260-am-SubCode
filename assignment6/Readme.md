# Simple Binary Tree
The plan is to make a simple binary tree, and due to its simple nature it wont have many of the optimization features implemented in red-black, AVL, or WAVL trees.
### Precursors
I want to use doubly linked nodes for the tree, the nodes will have the following components.
- int value: contains an integer for the value of the node.
- binarynode* left: contains a node of lesser magnitude if there is one.
- binarynode* right: contains a node of right magnitude if there is one.

## Functions
### addvalue(int value)
Lines 20-28 and 44-62 in binarytree.hpp
This function will add a specified value to the tree via a helper function that does so recursively.
### findvalue(int value)
Lines 30-32 and 64-74 in binarytree.hpp
This function will return value if it is in the tree, otherwise it will throw std::domain_error. It finds the value through a helper function.
### sizeoftree()
Lines 34-36 and 76-85 in binarytree.hpp
This function returns the size of the tree using a post order traversal to do so. This function accepts no arguments.
### removevalue(int value)
Lines 38-40, 87-119, and 121-140 in binarytree.hpp
This function uses several helper functions to remove a value from the tree.
## Time complexity
All of the aforementioned functions have a operation time of O(n). This is due to the unoptimised nature of the tree and could be reduced to O(log(n)) for addvalue,findvalue, and removevalue by making sure that the tree stays balanced. Due to how sizeoftree() is a post-order traversal its computation time will always be O(n)

## Testing
I have included the file main.cpp which tests each of the above functions in many cases. Its output should look like this:
4
3
5
0
-20 Value does not exist in list.
My tree currently has 6 nodes.
Did 4 get removed? 1
Did 5 get removed? 1
Did -2 get removed? 1
Did 0 get removed? 1
Did -1 get removed? 1
Did -10 get removed? 0
Did 3 get removed? 1
Did 7 get removed? 1
