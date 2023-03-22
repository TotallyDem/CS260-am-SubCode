#include <algorithm>
#include <limits>
#include <set>
#include <string>
#include <vector>
struct branch;
// This the the struct for a node inside the graph datastructure
struct node {
    std::string name;
    std::vector<branch*> connections;
};
// This branch struct connects two nodes in the graph datastructure.
struct branch {
    node* destination;
    unsigned int weight;
    branch(node* dest, unsigned int weigh) : destination(dest), weight(weigh) {}
};
// This the the class for a graph datastructure.
class graph {
    public:
        // This adds the node to the graph. Note, the node will have no connections.
        int add_node(std::string nodename) {
            if (nodes.size() > 0) {
                bool exists = false;
                for(auto n : nodes) {
                    if (n->name == nodename) exists = true;
                }
                if(!exists) {
                    node* newnode = new node;
                    newnode->name = nodename;
                    nodes.push_back(newnode);
                }
                return !exists;
            }
            else {
                node* newnode = new node;
                newnode->name = nodename;
                nodes.push_back(newnode);
                return 1;
            }
        }
        // This removes a node and all refrences to that node from connected nodes.
        int remove_node(std::string nodename) {
            node* deletednode = nullptr;
            for (int i = 0; i < nodes.size(); ++i) {
                if (nodes[i]->name == nodename) {
                    deletednode = nodes[i];
                    break;
                }
            }
            if (deletednode != nullptr) {
                for (int i = 0; i < deletednode->connections.size(); ++i) {
                    node* inspectednode = deletednode->connections[i]->destination;
                    for (int j = 0; j < inspectednode->connections.size(); ++j) {
                        if(inspectednode->connections[j]->destination == deletednode) {
                            branch* deletedbranch = inspectednode->connections[j];
                            inspectednode->connections.erase(inspectednode->connections.begin()+j);
                            delete deletedbranch;
                            --j;
                        }
                    }
                }
                while (deletednode->connections.size() > 0) {
                    branch* deletedbranch = deletednode->connections.back();
                    deletednode->connections.pop_back();
                    delete deletedbranch;
                }
                delete deletednode;
            }
            return (deletednode != nullptr);
        }
        // Adds a weighted edge between two nodes.
        int add_edge(std::string nodename1, std::string nodename2, unsigned int weight) {
            if (nodename1 != nodename2) {
                node* node1 = nullptr;
                node* node2 = nullptr;
                for (int i = 0; i < nodes.size(); ++i) {
                    if (nodes[i]-> name == nodename1) node1 = nodes[i];
                    if (nodes[i]-> name == nodename2) node2 = nodes[i];
                }
                if ((node1 != nullptr)&&(node2 != nullptr)) {
                // checks to see if a duplicate path exists.
                    for (auto b : node1->connections) {
                        if (b->destination == node2) {
                            if (b->weight > weight) {b->weight = weight; return 2;}
                            return 0;
                        }
                    }
                    branch* connection1 = new branch(node2, weight);
                    branch* connection2 = new branch(node1, weight);
                    node1->connections.push_back(connection1);
                    node2->connections.push_back(connection2);
                    return 1;
                }
            }
            return 0;
        }
        // Removes an edge between two nodes.
        int remove_edge(std::string nodename1, std::string nodename2) {
            if (nodename1 != nodename2) {
                node* node1 = nullptr;
                node* node2 = nullptr;
                for (auto n : nodes) {
                    if (n->name == nodename1) node1 = n;
                    if (n->name == nodename2) node2 = n;
                }
                if ((node1 != nullptr)&&(node2 != nullptr)) {
                    for (int i = 0; i < node1->connections.size(); ++i) {
                        if (node1->connections[i]->destination == node2) {
                            node1->connections.erase(node1->connections.begin()+i);
                        }
                    }
                    for (int i = 0; i < node2->connections.size(); ++i) {
                        if (node2->connections[i]->destination == node1) {
                            node2->connections.erase(node1->connections.begin()+i);
                        }
                    }
                }
                return 1;
            }
            return 0;
        }
        // Shortest path algorithm for the connection between two nodes. Returns the minimum weight to get to the destination node.
        int shortest_path(std::string startnode, std::string endnode) {
            // Find the nodes corresponding to the start and end node names
            node* start = nullptr;
            node* end = nullptr;
            for (auto n : nodes) {
                if (n->name == startnode) start = n;
                if (n->name == endnode) end = n;
            }
            if (start == nullptr || end == nullptr) {
                // Return a large value to indicate that the path doesn't exist
                return INT_MAX;
            }

            // Create a vector to store the tentative distances to each node
            std::vector<int> dist(nodes.size(), INT_MAX);

            // Set the distance to the start node to 0
            dist[std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), start))] = 0;

            // Create a set to store the unvisited nodes
            std::set<node*> unvisited;
            for (auto n : nodes) {
                unvisited.insert(n);
            }

            // Dijkstra's algorithm
            while (!unvisited.empty()) {
                // Find the unvisited node with the smallest tentative distance
                node* current = *std::min_element(unvisited.begin(), unvisited.end(),
                    [&](const node* n1, const node* n2) { return dist[std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), n1))] < dist[std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), n2))]; });
                if (current == end) {
                    // We have found the shortest path to the end node, so return its distance
                    return dist[std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), current))];
                }
                unvisited.erase(current);

                // Update the tentative distances of the unvisited neighbors of the current node
                for (auto b : current->connections) {
                    int alt = dist[std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), current))] + b->weight;
                    int idx = std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), b->destination));
                    if (alt < dist[idx]) {
                        dist[idx] = alt;
                    }
                }
            }

            // If we have visited all nodes and haven't found the end node, it means there is no path
            return INT_MAX;
        }
        // Minimum span tree 
        int min_span_tree(std::string startingnode) {
            // Find the starting node.
            node* start = nullptr;
            for (auto n : nodes) { // O(n)
                if (n->name == startingnode) {
                    start = n;
                    break;
                }
            }
            if (start == nullptr) return -1; // Starting node not found.
            // Initialize the set of visited nodes and the set of unvisited nodes.
            std::set<node*> visited;
            std::set<node*> unvisited;
            for (auto n : nodes) { // O(n)
                if (n == start) unvisited.insert(n);
                else unvisited.insert(n);
            }
            // Initialize the minimum spanning tree.
            int minspan = 0;
            // Repeat until all nodes are visited.
            while (!unvisited.empty()) {
                // Find the node in the unvisited set with the smallest edge weight to a visited node.
                node* current = nullptr;
                branch* smallest = nullptr;
                int smallest_weight = std::numeric_limits<int>::max();
                for (auto n : unvisited) {
                    for (auto b : n->connections) {
                        if (visited.find(b->destination) != visited.end() && b->weight < smallest_weight) {
                            current = n;
                            smallest = b;
                            smallest_weight = b->weight;
                        }
                    }
                }
                if (current == nullptr) return -1; // Graph is not connected.
                // Add the node and branch to the minimum spanning tree.
                visited.insert(current);
                unvisited.erase(current);
                minspan += smallest_weight;
            }
            return minspan;
        }
    private:
        std::vector<node*> nodes;
};