#include <iostream>
#include "bst.cpp"

using namespace std;

int main() {
    TreeFunctions ftr; // initializes class shorthand

    treeNode* root = NULL;   // Initialize empty tree

    // Inserts values into list
    root = ftr.Insert(root,15); root = ftr.Insert(root,10);
    root = ftr.Insert(root,20); root = ftr.Insert(root,25);
    root = ftr.Insert(root,30); root = ftr.Insert(root,35);
    root = ftr.Insert(root,40); root = ftr.Insert(root,45);
    root = ftr.Insert(root,50); root = ftr.Insert(root,55);
    root = ftr.Insert(root,60); root = ftr.Insert(root,65);

    // Prints list via inorder traversal
    cout<<"In order traversal of the given tree"<<endl;
    ftr.Print(root);

    // Deletes value 15 using successor function
    cout<<"Delete value 15"<<endl;
    root = ftr.Successor(root,15);
    cout<<"In order traversal of modified tree"<<endl;
    ftr.Print(root);

    // Lets user search for number
    // Try non existent number for testing purposes
    int num;
    cout<<"Enter a number: "<< endl;
    cin>>num;
    ftr.Search(root,num);

    return 0;
}