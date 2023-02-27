#include <iostream>
#include "node.h"

using namespace std;

class TreeFunctions {
    private:
        // Uses manual allocation (new) to create new node using data
        treeNode* createNode(int new_data) {
            treeNode *new_trNode = new treeNode();
            new_trNode->data = new_data;
            new_trNode->left = new_trNode->right = NULL;
            return new_trNode;
        }
        // Returns the minimum data value found in tree
        treeNode* minData(treeNode* node) {
            treeNode* current = node;
            // Loop through to find left data value
            while(current && current->left != NULL) {
                current = current->left;
            }
            return current;
        }

    public:
        // Inserts new node using createNode function
        treeNode* Insert(treeNode* root, int new_data) {
            if(root == NULL) { // If list is empty
                root = createNode(new_data);
            }
            else if(new_data <= root->data) {
                // If new data is less than or equal to roots data insert into left
                root->left = Insert(root->left,new_data);
            }
            else { // If new data is greater than roots data insert into right
                root->right = Insert(root->right,new_data);
            }
            return root;
        }

        // Deletes the data and replaces a new root node
        treeNode* Successor(treeNode* root, int data) {
            if(root == NULL) return root;

            if(data < root->data) // If data < root data then its in the left subtree
                root->left = Successor(root->left, data);

            else if(data > root->data) // if data > root data then its in the right subtree
                root->right = Successor(root->right, data);
            
            else { // If data is the same as the roots data then this is the deleted node
                if(root->left == NULL and root->right == NULL) return NULL;
                
                else if(root->left == NULL) {
                    treeNode* temp = root->right;
                    free(root);
                    return temp;
                }
                else if(root->right == NULL) {
                    treeNode* temp = root->left;
                    free(root);
                    return temp;
                }

                treeNode* temp = minData(root->right);
                root->data = temp->data; // Copies the successor
                root->right = Successor(root->right, temp->data); // Deletes the successor
            }
            return root;
        }

        // Searches list for specific data value
        void Search(treeNode* root, int data) {
            if(root == NULL) cout<<"Data not found in list"<<endl;
            else if(root->data == data) cout<<"Data found in list"<<endl;
            else if(data <= root->data) return Search(root->left,data);
            else return Search(root->right,data);
        }

        // Inorder traversal method of printing tree
        void Print(treeNode* root) {
            if(root != NULL) {
                Print(root->left);
                cout<<root->data<<endl;
                Print(root->right);
            }
        }
};