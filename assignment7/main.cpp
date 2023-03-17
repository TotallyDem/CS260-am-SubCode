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
    // Initial add testing
    cout << "Adding \"Hello world!\"..." << endl;
    Table.add("Hello world!");
    cout << "Does \"Hello world!\" exist? " << Table.get("Hello world!") << endl;
    // Initial remove testing
    cout << "Removing \"Hello world!\"..." << endl;
    Table.remove("Hello world!");
    cout << "Does \"Hello world!\" exist? " << Table.get("Hello world!") << endl;
    // Collison testing
    cout << "Adding \"ab\"" << endl;
    Table.add("ab");
    cout << "Adding \"ba\"" << endl;
    Table.add("ba");
    cout << "Does \"ab\" and \"ba\" exist? " << (Table.get("ab") && Table.get("ba")) << endl;
    cout << "COMPLICATED HASHTABLE TESTS COMPLETE" << endl;
    return 0;
}