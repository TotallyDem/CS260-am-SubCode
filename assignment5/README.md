The plan is to make a low - high auto sorted linked list. For the base linked list code I will recycle the code from the last assignment. In order to test the linked list, I could print out all the items in the list and visually verify that they are all in correct order. Alternatively I could iterate through the list and see if all the values follow the rule set.

To be honest, all that needs to change is the add function, instead of being an insert it just needs to automatically know where to put the values.

The linked list will support any datatype that supports '>' or '<' symbols

I will need to additionally test adding the lowest value item, adding highest value item, and a middle value item.

Complexity analysis of the functions:
assorted_list::add(value) : O(n) lines {24-51} Meets reqs

assorted_list::remove (index): O(n) lines {53-82} Meets reqs

assorted_list::get (index) : O(n) lines {84-103} 
If the index is greater than halfway through the list, it counts from the back to avoid extra counting. This changes the worst case from n to n/2 in exchange for doing some extra comparisons to see where to start from.

assorted_list::len (void) : O(1) lines {104-106} Not necessary for reqs.