# Linked List Arbitrary Operations

## Purpose
This program serves as a test for various functions and operations that can be performed using linked lists. It includes the ability to create, insert, find, and remove 
elements from a linked list using pointers.

## Implementation
The program will be based around ID lists, in which the linked list will contain a single variable called id
There will be five functions + main, and three structs
The five functions will be a create function, insert function, delete function, search position, and a list function
  Create function will take input from user and create a new id using it
  Insert funciton will take input from user and place it in the middle of the list
  Remove function will take input from user, search for the input within the list, if found it will delete the id
  Search Pos function will take input from user, move through the list based on users input, and output id found at that position
  List function will display the ids found in the list
The three structs will be the linked list, a search struct, and an equals struct
  The search struct will be used in the create and insert functions and the equals struct will be used in the remove function
Main will include a while loop menu that contains a switch case operator that takes the users input and allows them to choose either creating, inserting, deleting, or 
listing ids

## Tests
  1. Created id: 54321
  2. Displayed ids: console output 54321
  3. Created id: 12345
  4. Displayed ids: console output 54321 12345
  5. Inserted id: 21435
  6. Displayed ids: console output 54321 21435 12345
  7. Removed id: 54321
  8. Displayed ids: console output 21435 12345
  9. Searched Pos: 1 console output 21435
  10. Searched Pos: 2 console output 12345
