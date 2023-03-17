#include "hashtable.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    cout << "SIMPLE HASHTABLE TESTING" << endl;
    SimpleHashTable SimpleTable(30);
    // Basic add test.
    cout << "Adding value 15..." << endl;
    SimpleTable.add(15);
    cout << "Does 15 exist? " << SimpleTable.get(15) << endl;
    // Value overwrite test.
    cout << "Adding value 45..." << endl;
    SimpleTable.add(45);
    cout << "Does 15 exist? " << SimpleTable.get(15) << endl;
    cout << "Does 45 exist? " << SimpleTable.get(45) << endl;
    // Removal test
    cout << "Removing value 45..." << endl;
    SimpleTable.remove(45);
    cout << "Does 45 exist? " << SimpleTable.get(45) << endl;
    // Adding negative numbers
    cout << "Adding value -104..." << endl;
    SimpleTable.add(-104);
    cout << "Does -104 exist? " << SimpleTable.get(-104) << endl;
    cout << "SIMPLE HASHTABLE TESTS COMPLETE" << endl << endl;
    cout << "STARTING COMPLICATED HASHTABLE TESTS" << endl;
    HashTable Table(26);
    cout << "Table.Table[0][0]" << "TEST" << endl;
    
    return 0;
}