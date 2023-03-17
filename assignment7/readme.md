# Hashtable Design:
### Fundamental Idea:
I will use an array to store the data for the table. Each index in the array will contain another array. Each arrays size will be dynamic. I plan to use the std::vector to handle expansion for collisions.
## Functions:
- add(string) Adds the string into the hashtable if it is not in it already.
- bool get(string) Returns a boolean true or false depending on whether or not the string is at the specified index.
- remove(string) Removes the string from the hash table, if it exists.
- private: int hash(string) Uses a hashing function to convert the string to an index value, this will be used for the remove and add functions to find the location of where the object should be. I will just convert the string's charater's to ascii value for simplicity sake and use modulus on the total.

# Simplified Design:
### Fundamental Idea:
I will use an array to store the data for the table. Each index in the array will contain an int. In the case of a collision, the table will simply overwrite the value.
## Functions:
- add(int)
- bool get(int)
- remove(int)
- private: int hash(int) Uses a modulus operator to convert the int to an index value, this will be used for the remove and add functions to find the location of where the object should be.