# Hashtables in C++
# View Hashtable.jpg for diagram
## Purpose 
The purpose of this code is to show the usage of hashtables and their respective functions. First I will create a simple hashtable that resolves collision by overwriting
the old value with a new value. Then I will create an improved hashtable that incoorporates a more complex hashfunction to avoid collision that uses chaining.

## Implementation
The idea behind this program is to store a key with a persons name similar to a phonebook. I used 10 hashgroups and then created a paired list with an int and a string. Then I created four functions, a hashfunction, an insert funciton, a remove function, and a print function. The hashfunction uses the modulo operator to take an int (key) and place it in the respective hashgroup based on the last digit of the number. This is done because I only used 10 hashgroups, so if it starts at 0 and goes through 9, I only really need to check the last digit since it can only be 0-9. Then the insert function I used the hashfunction that I previously made to initialize which list (cell) the key will be placed into. Then I check if the key exists and assume false, then I validate the false claim using a for loop, if the key doesn't exist the key is then placed into the respective list. However, if the key does exist, then the cell is replaced with the new key, prompting the user that the key was replaced. The remove function is essentially the same as the previous, but mirrored, so if the key exists the cell is erased and the new iterator is set to the empty cell and if the key doesn't exist the console tells user that the key was not found. Lastly the print function checks if the table is empty, if not then it cycles through printing each key and name respectively.

## Tests
- Test empty list check on empty list
- Test printing empty list
- Test insertion
- Test inserting duplicate
- Test removal
- Test removal of non-existent entry
- Test printing occupied list
- Test empty list check on occupied list
