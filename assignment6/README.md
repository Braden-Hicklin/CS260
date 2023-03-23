# Binary Search Tree Assignment
## Purpose
The purpose of this program is to show proficency with the usage of binary search trees and their respective functions. 
## Functions
There are four active functions in this program: Insert, Successor, Search, and Print
  Insert: Inserts a new data point into the doubly linked list
  Successor: Deletes data point and finds appropriate replacement node
  Search: Searches through list for specific data point
  Print: Prints list using inorder traversal method
There are two utility functions in the program: createNode, and minData
  createNode: Private function that dynamically creates new node using new operator (malloc)
  minData: Returns the minimum value found in the tree
## Reflection
I was surprised to learn that this method of dynamic allocation of memory and functions associated with it is something that I am already quite familiar with and have
done in multiple projects in previous courses. For example, in 133c I used a binary search tree to dynamically create, insert, delete, and modify two doubly linked lists
that simulated a schools database for students including ID's, Names, and Grade. After realizing this the project became much easier and I was able to complete the 
assignment with little to no issues. The only real issue I ran into was trying to understand the difference between a basic deletion function and a successor function. 
After some research and rewatching some of the class lectures I realized I was just thinking too linearly and not in a way that fits binary search trees memory layout.
## Complexity Analysis
I struggle with big O notation so this may not be correct, but I will attempt to analyze the functions:
createNode should be O(1) since there is not additionaly iteration being performed its simply creating a single node not inserting it or altering an existing node.
minData would be O(n) since it has to traverse through the tree in order to find the min data value.
Insert would also be O(n) since it has to iterate through the tree in order to place the newly created node.
Successor would be O(log n) since I used a doubly linked list the successor function has to check for a right subtree; back up to linked node for which it is the left child.
The Search function would also be O(n) since it just has to traverse the list
The print would be O(n), this I'm unsure of because the inorder traversal would run the function n number of times, n being the number of items in the list.
