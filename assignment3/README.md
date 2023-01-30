# Queue design
This queue has 4 functions. The functions are 
 - peek() this function will return the value of the front of the list
 - enqueue(value) this function will add the value specified to the end of the queue.
 - dequeue() this function will return value of the front of the queue and remove it from the queue.
 - queuestate() this function returns a boolean value which changes when the list is empty.

The queue will be templateable, meaning you can use it to store ints, strings, or even more queues.

A deconstructor included, but effectiveness not garuenteed.

 ## Queue files
  - "main.cpp" Test implementation of the queue
  - "queue.hpp" The main queue code, which is a linked list.
  - "node.hpp" The node code, which is the underlying link in the linked list.

### Tests to include in main.cpp
 - Test template support with at least two datatypes.
 - Test the queuestate() function with a while loop to empty the queue to console.