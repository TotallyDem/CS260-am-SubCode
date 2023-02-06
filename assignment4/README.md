# Assorted List Design

## Functions:
- add(index, value) Inserts a node before the specified index.
- remove(index) Removes the node at the specified index, with index starting at 0. Returns boolean failure state.
- get(index) Returns the value of the node at the specified index.
- len() Returns the current length of the list.

### Features: 
- Error catching on get, you can use try to prevent program from crashing.
- add() clamps indexes so that if you are below 0 or exceed the length of the list it will append to the end or the front.
- Included testing file. Check driver.cpp and compare it to the expected output in the aptly named expectedoutput.txt

## What Lines of code to look at:
#### assorted_list.hpp
- add() 24-53
- remove() 55-84
- get() 86-99

### Complexity analysis:
#### add()
- Adding to the end or the front: O(1)
- Adding to anywhere else O(n)
#### remove()
- Removing front or end O(1)
- Removing anywhere else O(n), could be further optimised such that if the index is greater than half the list's length, it counts from the back, taking advantage in the fact that the list is doubly linked.
#### get()
- Getting front or back O(1)
- Getting anywhere else O(n)
#### len()
- O(1) just returns a variable's value.