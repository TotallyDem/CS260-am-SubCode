# Queue design
This queue has 4 functions. The functions are 
 - peek() this function will return the value of the front of the list
 - enqueue(value) this function will add the value specified to the end of the queue.
 - dequeue() this function will return value of the front of the queue and remove it from the queue.
 - queuestate() this function returns a boolean value which changes when the list is empty.

The dequeue() and peek() functions will return std::out_of_range when they are used on an empty queue.

The queue will be templateable, meaning you can use it to store ints, strings, or even more queues.

A deconstructor included, but effectiveness not garuenteed.

## Queue files
 - "main.cpp" Test implementation of the queue
 - "queue.hpp" The main queue code, which is a linked list.
 - "node.hpp" The node code, which is the underlying link in the linked list.

### Tests to include in main.cpp
 - Test template support with at least two datatypes.
 - Test the queuestate() function with a while loop to empty the queue to console.
-----------------------
# How complex are my functions?
 - peek() is as simple as it gets, all in two lines, I don't know how to improve it.
 - enqueue() could be simplified significantly and become more efficient for longer queues if I tracked the end node of the linked list. Other than that, it's relatively simple.
 - dequeue() really simple, not much room for improvement.
 - queuestate() a simple comparison, can't get much simpler than that.
-----------------------------------
# What lines meet the code requirements?
 - enqueue() is located in "queue.hpp" lines 14-28
 - dequeue() is located in "queue.hpp" lines 33-40
 - peek() is located in "queue.hpp" lines 45-48
----------------------------------
# What is the expected output of the main.cpp file?
<p>Hello<br>
Hello<br>
<br>
1 1<br>
3 3<br>
2 2<br>
4 4<br>
<br>
peek failed succesfully. peek only functions on a queue with data<br>
dequeue failed succesfully. dequeue only functions on a queue with data<br>
<br>
All tests passed.</p>