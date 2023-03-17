#include <string>
#include <vector>
using std::vector;
using std::string;
class HashTable {
    public:
        // This function is the initializer for the hashtable O(1) or O(n) depending on how system memory allocation works. Apparently it's different depending on OS.
        HashTable(int initialsize) {
            Length = initialsize;
            Table = new vector<string>[initialsize];
        }
        // This is the destructor for the hashtable. O(n)
        ~HashTable() {
            delete[] Table;
        }
        // This function adds a value to the table, if it is not already in it. Has a worst case time complexits of n but average case of 1.
        void add(string value) {
            int hashv = hash(value);
            bool exists = false;
            for (int c = 0; c < Table[hashv].size(); ++c) {
                if (Table[hashv][c] == value) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                Table[hashv].push_back(value);
            }
        }
        // This function removes a value from the table, if it exists. Has a worst case time complexits of n but average case of 1.
        void remove(string value) {
            int hashv = hash(value);
            for (int c = 0; c < Table[hashv].size(); ++c) {
                if (Table[hashv][c] == value) {
                    Table[hashv].erase(Table[hashv].begin() + c);
                    break;
                }
            }
        }
        // This function returns true or false if a value exits in the table. Worst case time complexits of n but average of 1.
        bool get(string value) {
            int hashv = hash(value);
            for (int c = 0; Table[hashv][c] != ""; ++c) {
                if (Table[hashv][c] == value) {
                    return true;
                }
            }
            return false;
        }
    private:
        vector<string>* Table;
        int Length;
        // This function hashes the value of the string provided. It has a time complexity of O(1).
        int hash(string value) {
            int hashvalue = 0;
            for (int c = 0; c < value.length(); ++c) {
                hashvalue += (int)value[c];
            }
            return hashvalue % Length;
        }
};
class SimpleHashTable {
    public:
        // This function is the constructor for the SimpleHashTable class. An empty position is initialized to INT_MIN
        SimpleHashTable(int size) {
            Table = (int*)malloc(sizeof(int)*size);
            length = size;
            for (int c = 0; c < length; ++c) {
                Table[c] = INT_MIN;
            }
        }
        // This function is the destructor for the SimpleHashTable class.
        ~SimpleHashTable() {
            free(Table);
        }
        // This function will add the value to the hashtable, overwriting collisions O(1)
        void add(int value) {
            Table[hash(value)] = value;
        }
        // This function will remove the value from the hashtable, if it exists O(1)
        void remove(int value) {
            if (Table[hash(value)] == value) {
                Table[hash(value)] = INT_MIN;
            }
        }
        // Returns whether or not the value exits in the table. O(1)
        bool get(int value) {
            if (Table[hash(value)] == value) {
                return true;
            } else {
                return false;
            }
        }
    private:
        int* Table;
        int length;
        // Returns a hash index for the value. Has checks to make sure there is no negative index. O(1)
        int hash(int value) {
            int hashvalue = value % length;
            if (hashvalue < 0) {
                hashvalue = -hashvalue;
            }
            return hashvalue;
        }
};