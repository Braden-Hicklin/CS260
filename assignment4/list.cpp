#include <iostream>

using namespace std;

// linked list 
struct node {
    int id;
    node * next;
};

class Linked_List {
    private:
        node *head = NULL;

        node *searchList(int new_id){
            if(head == NULL) return head;
            node *current = head;
            node *prev = head;
            // returns pointer to element whose id is less than or equal to input
            // best used for basic non-destructive functions (ie creating node)
            while(current){
                if(current->id == new_id) return current;
                if(current->id > new_id) return prev;
                prev = current;
                current = current->next;
            }
            
            return current;
        }

        // precise search through the list
        node *searchListEq(int new_id){
            if(head == NULL) return head;
            node *current = head;
            node *prev = head;
            // returns pointer to element whose id is equal to input 
            // best used for exact ids (ie deleting)
            while(current){
                if(current->id == new_id) return current;
                prev = current;
                current = current->next;
            }
            
            return current;
        }
    public:
        void addID(int new_id) {
            node *newNode = new node;
            newNode->id = new_id;
            newNode->next = NULL;
            
            if(head == NULL) {
                head = newNode;
                return;
            }
            node *current = head;
            while(current) {
                if(current->next == NULL) {
                    current->next = newNode;
                    return;
                }
                current = current->next;
            }
        }

        // creates a new node in the middle of the list
        void insertID(int new_id) {
            node *ptr = searchList(new_id);
            node *newNode = new node;
            newNode->id = new_id;
            node *current = head;
            while(current) {
                if(current == ptr) {
                    newNode->next = current->next;
                    current->next = newNode;
                    return;
                }
                current = current->next;
            }
        }

        // gets the id for a node found at a specific position
        void getID(int new_id) {
            struct node *record = head;
            while(new_id > 1) {
                record = record->next;
                new_id--;
            }
            cout << record->id << endl;
        }

        // removes specific node based on id
        void deleteID(int new_id) {
            node *ptr = searchListEq(new_id);
            if(ptr == NULL) {
                cout << "No list containing ID: " << new_id << endl;
            }
            if(ptr == head) {
                head = ptr->next;
                return;
            }
            node *current = head;
            node *prev = head;
            
            while(current) {
                if(current == ptr) {
                    prev->next = current->next;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }

        // lists all ids
        void display() {
            struct node *record = head;
            while(record) {
                cout << record->id << " ";
                record = record->next;
            }
        } 
};