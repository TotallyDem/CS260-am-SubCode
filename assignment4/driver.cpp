#include <iostream>
#include "assorted_list.hpp"

int main (void) {
    assorted_list<int> list;
    std::cout << "Testing adding, reading, removing number, removing on empty list, removing out of bounds." << std::endl;
    list.add(0, 10);
    std::cout << list.get(0) << std::endl;
    std::cout << list.remove(-10) << std::endl;
    std::cout << list.remove(20) << std::endl;
    std::cout << list.remove(0) << std::endl;
    std::cout << list.remove(0) << std::endl;
    try {
        list.get(0);
    } catch(std::out_of_range& e) {
        std::cout << "get failed succesfully. " << e.what() << std::endl;
    }
    list.add(0, 0);
    try {
        list.get(1);
    } catch(std::out_of_range& e) {
        std::cout << "get failed succesfully. " << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Testing adding to end of list" << std::endl;
    for (int i = 1; i < 5; ++i) {
        list.add(i, i);
    }
    for (int i = 0; i < list.len(); ++i) {
        std::cout << "list[" << i << "] : " << list.get(i) << std::endl; 
    }
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Testing adding in middle of list" << std::endl;
    list.add(3,42);
    for (int i = 0; i < list.len(); ++i) {
        std::cout << "list[" << i << "] : " << list.get(i) << std::endl; 
    }
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Testing adding to front of list" << std::endl;
    list.add(0, -1);
    for (int i = 0; i < list.len(); ++i) {
        std::cout << "list[" << i << "] : " << list.get(i) << std::endl; 
    }
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "testing negative and exceeding length add requests" << std::endl;
    list.add(-30, -2);
    list.add(100, 203);
    for (int i = 0; i < list.len(); ++i) {
        std::cout << "list[" << i << "] : " << list.get(i) << std::endl; 
    }
    return 0;
}