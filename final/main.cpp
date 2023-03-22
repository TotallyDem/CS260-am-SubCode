#include "graph.hpp"
#include <iostream>

int main (void) {
    graph testgraph;
    // Node adding test.
    std::cout << "Adding node \"1\" " <<testgraph.add_node("1") << std::endl;
    std::cout << "Adding node \"1\" " <<testgraph.add_node("1") << std::endl;
    std::cout << "Adding node \"2\" " <<testgraph.add_node("2") << std::endl;
    // Connecting edges
    std::cout << "Adding edge between \"1\" and \"2\" " << testgraph.add_edge("1","2",5) << std::endl;
    std::cout << "Adding edge between \"1\" and \"2\" " << testgraph.add_edge("1","2",7) << std::endl;
    std::cout << "Adding edge between \"1\" and \"2\" " << testgraph.add_edge("1","2",3) << std::endl;
    std::cout << "Adding node \"3\" " <<testgraph.add_node("3") << std::endl;
    std::cout << "Adding node \"4\" " <<testgraph.add_node("4") << std::endl;
    std::cout << "Adding node \"5\" " <<testgraph.add_node("5") << std::endl;
    std::cout << "Adding edge between \"3\" and \"2\" " << testgraph.add_edge("3","2",1) << std::endl;
    std::cout << "Adding edge between \"390\" and \"232\" " << testgraph.add_edge("390","232",1) << std::endl;
    std::cout << "Finding the shortest path between \"1\" and \"3\" " << testgraph.shortest_path("1","3") << std::endl;
    std::cout << "Finding the shortest path between \"1\" and \"5\" " << testgraph.shortest_path("1","5") << std::endl;
    std::cout << "Finding the shortest path between \"1\" and \"300\" " << testgraph.shortest_path("1","300") << std::endl;
    std::cout << "Finding the shortest path between \"290\" and \"300\" " << testgraph.shortest_path("290","300") << std::endl;
    graph newgraph;
    std::cout << "Creating a new graph" << std::endl;
    std::cout << "Adding a new node 'a'" << newgraph.add_node("a") << std::endl;
    std::cout << "Adding a new node 'b'" << newgraph.add_node("b") << std::endl;
    std::cout << "Adding edge between \"a\" and \"b\" of weight 1 " << newgraph.add_edge("a","b",1) << std::endl;
    std::cout << "Total weight of min span tree starting from a" << newgraph.min_span_tree("a") << std::endl;
    std::cout << "Removing edge between \"a\" \"b\" " << newgraph.remove_edge("a", "b") << std::endl;
    std::cout << "Total weight of min span tree starting from a " << newgraph.min_span_tree("a") << std::endl;
    return 0;
}
