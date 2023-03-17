#include <string>
#include <vector>
using std::vector;
using std::string;
class HashTable {
    public:
        // This function is the initializer for the hashtable
        HashTable(int initialsize) {
            Length = initialsize;
            Table = new vector<string>[initialsize];
        }
        ~HashTable() {
            delete[] Table;
        }
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
        void remove(string value) {
            int hashv = hash(value);
            for (int c = 0; c < Table[hashv].size(); ++c) {
                if (Table[hashv][c] == value) {
                    Table[hashv].erase(Table[hashv].begin() + c);
                    break;
                }
            }
        }
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
        int hash(string value) {
            int hashvalue = 0;
            for (int c = 0; c < value.length(); ++c) {
                hashvalue += (int)value[c] * 2**c;
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
        void add(int value) {
            
            Table[hash(value)] = value;
        }
        void remove(int value) {
            if (Table[hash(value)] == value) {
                Table[hash(value)] = INT_MIN;
            }
        }
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
        int hash(int value) {
            int hashvalue = value % length;
            if (hashvalue < 0) {
                hashvalue = -hashvalue;
            }
            return hashvalue;
        }
};