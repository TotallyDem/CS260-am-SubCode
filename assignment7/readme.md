# Hashtable Design:
Each hashtable is contained in hashtable.hpp
### Fundamental Idea:
I will use an array to store the data for the table. Each index in the array will contain another array. Each arrays size will be dynamic. I plan to use the std::vector to handle expansion for collisions.
## Functions:
- add(string) Adds the string into the hashtable if it is not in it already. Lines 16-29
- remove(string) Removes the string from the hash table, if it exists. Lines 30-39
- bool get(string) Returns a boolean true or false depending on whether or not the string is at the specified index. Lines 40-49
- private: int hash(string) Uses a hashing function to convert the string to an index value, this will be used for the remove and add functions to find the location of where the object should be. I will just convert the string's charater's to ascii value for simplicity sake and use modulus on the total. Lines 53-60

# Simplified Design:
### Fundamental Idea:
I will use an array to store the data for the table. Each index in the array will contain an int. In the case of a collision, the table will simply overwrite the value.
## Functions:
- add(int) Add value to hashtable, overwriting if collision. Lines 76-79
- remove(int) Removes value if it exists. Lines 80-85
- bool get(int) Returns whether or not the value exists in the table. Lines 86-93
- private: int hash(int) Uses a modulus operator to convert the int to an index value, this will be used for the remove and add functions to find the location of where the object should be. Lines 97-104

## Test File
The included main.cpp should have the following output:
SIMPLE HASHTABLE TESTING
Adding value 15...
Does 15 exist? 1
Adding value 45...
Does 15 exist? 0
Does 45 exist? 1
Removing value 45...
Does 45 exist? 0
Adding value -104...
Does -104 exist? 1
SIMPLE HASHTABLE TESTS COMPLETE

STARTING COMPLICATED HASHTABLE TESTS
Adding "Hello world!"...
Does "Hello world!" exist? 1
Removing "Hello world!"...
Does "Hello world!" exist? 1
Adding "ab"
Adding "ba"
Does "ab" and "ba" exist? 1
COMPLICATED HASHTABLE TESTS COMPLETE
