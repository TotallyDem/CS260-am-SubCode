# Graph datastructue
## Ideas
Each node will be identified with a string name. This way the user can specify nodes to go between without having a direct reference to them.

## Functions
- int add_node (string name) This will add a node with the specified name to the graph. It has a runtime of O(n) since I need to check for duplicate names. It returns 1 if the node was made or 0 if it was not. lines 22-41
- int remove_node (string name) This will remove the specified node. It will first remove all branches which go to or come from this node and then finally delete the node. It returns 1 or 0 depending on whether or not the node was deleted. lines 43-71
- int add_edge (string name1, string name2, unsigned int weight) This function will connect the two nodes with the specified names with a branch that has the weight specified. This does not allow parallel arcs or loops. Will be time complexity O(n) since I need to make sure no parallel arcs exist. This function returns 1 or 0 depening on whether or not the edge was made. If the function encounters a situation where an edge would be defined twice, before returning 0 it will lower the weight of the path if the new one would have been lower. In that case it will return a 2. lines 73-97
- void remove_edge (string name1, string name2) Removes the edge between the two specified nodes. If it exists. lines 93-122
- int shortest_path (string startname, string endname) Finds the minimum weight of the path that connects the two nodes. It then returns this minimum weight, it does not return the path. I will use dijkstra's algorithm for this probably. O(n^2) lines 124-172
- int min_span_tree(string startnode) Finds the minimum spanning tree starting from the specified node. It then returns the total weight of all branches in the tree. I will probably use prim's algorithm for this. If the tree is disconnected the function will return -1 since there is no minimum weight tree which connects all nodes. O(n^2*logn). lines 174-215

## Tests
- I can test the add_node() function by adding nodes, then by adding a node who already has a name.
- I can test remove_node() by removing a node that does exist and then one which does not exist.
- I can test add_edge() by adding an edge, then attempting to add another edge again, one when the new weight is lower and again when it is higher.
- I can test remove_edge() by first remoing an edge and getting a 1 and trying to remove an edge that does not exist and get a 0;
- I can test shortest_path() by trying it on two nodes that are connected and two which are disconnected.
- I can test min_span_tree() by using it on different subgraphs. I can test it on a complete subgraph and a isolated node.

## Expected output
Adding node "1" 1
Adding node "1" 0
Adding node "2" 1
Adding edge between "1" and "2" 1
Adding edge between "1" and "2" 0
Adding edge between "1" and "2" 2
Adding node "3" 1
Adding node "4" 1
Adding node "5" 1
Adding edge between "3" and "2" 1
Adding edge between "390" and "232" 0
Finding the shortest path between "1" and "3" 4
Finding the shortest path between "1" and "5" 2147483647
Finding the shortest path between "1" and "300" 2147483647
Finding the shortest path between "290" and "300" 2147483647
Creating a new graph
Adding a new node 'a'1
Adding a new node 'b'1
Adding edge between "a" and "b" of weight 1 1
Total weight of min span tree starting from a-1
Removing edge between "a" "b" 1
Total weight of min span tree starting from a -1