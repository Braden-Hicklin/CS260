#include <iostream>
#include "bst.cpp"

using namespace std;

int main() {
    // Initializes tree struct and class shorthand
    TreeFunctions trf;    
    treeNode* root = NULL;
   
    // Print empty list
    cout<<"Printing empty list"<<endl;
    trf.Print(root); // Should output " "
    
    // Search empty list for data value 10
    trf.Search(root,10); // Should output "data not found in list"

    // Insert single value (10) and print
    root = trf.Insert(root,10);
    trf.Print(root); // Should output "10"

    // Search for non existent value
    trf.Search(root,15); // Should output "data not found in list"

    // Search for existing value
    trf.Search(root,10); // Should output "data found in list"

    // Delete non existent value and print
    root = trf.Successor(root, 15); // Should do nothing
    trf.Print(root); // Should print "10"

    // Delete single value (10) and print
    root = trf.Successor(root,10); // Should delete 10
    trf.Print(root); // Should print empty list

    // Search for value that was deleted (10)
    trf.Search(root,10); // Should return "data not found in list"

    // Insert two values (10, 15) and print
    root = trf.Insert(root,10); root = trf.Insert(root,15);
    trf.Print(root); // Should output "10   15"

    // Search for one of two values (15)
    trf.Search(root,15); // Should output "data found in list"

    // Delete one of two values (15) and print
    root = trf.Successor(root,15);
    trf.Print(root); // Should output "10"

    return 0;
}