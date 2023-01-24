# Queue Design

For this queue design, the queue will be a linked list where the head will be the item first in queue.

#### Necessary information:
- What kind of data is stored in the queue
- Length of the queue
- Position of the head and tail of the linked list that contitutes the queue

## Relevant Commands
### enqueue(queuename, queuelength, item)
Appends item to the end of queuename and increments queuelength by one.
In order to do so it generates the object and makes the previous tail point to the new object.
Returns 0, 1, or 2+ depending on the success of the command.
- 0 : success
- 1 : wrong datatype
- 2+ : some other potential error (depends on the exact number)

### dequeue(queuename, queuelength)
Returns the value of the value of the head and removes it from the linked list, setting the head to the node that the previous head was pointing to. If this succeedes then it decrements queuelength by 1. 
If the action fails it returns an error.

### readN(queuename, queuelength, itempos)
Returns the (itempos)th item in the queue (From Head->Tail)
Raises an error if an error worthy conditon is met.
If itempos exceedes queuelength returns null.

# List Design
This list will be created as a linked list rather than an array. Since it makes adding an item partway into the list way easier.

#### Necessary Information
- The location of the head
- Data type stored in the list
- Thats it.

## Relevant Commands:

### insert(head, pos, data)
at the (pos)nth position down from the head, creates a new object, causes the previous object to point to it (if exists) and points to the next object while containing the value data. If an item is being inserted at the front of the list the function returns the position of a the new object, which points to the previous head. Else it returns the position of the head.

### remove(head, pos)
at the (pos)nth position down from the head, it causes the item before in the linked list to point to the item after the specified item. It then frees the specified item from the memory. If the item removed is the first one it returns the location of the second item to be used as the new head. Otherwise it returns the location of the head.