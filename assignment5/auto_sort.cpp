#include <iostream>

using namespace std;

struct Node {
    int id;
    Node * next;
};

class Auto_Sort {
    private: 
        // initializes head/front of Linked List
        Node *head;
        
        // search function modified from class example
        Node *find_previous_node(int id) {
            Node *future = head->next;
            Node *current = head;
            while(future != nullptr && id > future->id) {
                current = future;
                future = future->next;
            }
            
            return current;
        }
        
        // precise search for element
        Node *precise_search(int i){
            if(head == NULL) return head;
            Node *current = head;
            Node *prev = head;
            // returns pointer to element whose id is equal to input 
            // best used for exact ids (ie deleting)
            while(current){
                if(current->id == i) return current;
                prev = current;
                current = current->next;
            }
            
            return current;
        }
    
    public:
        Auto_Sort() {
            head = nullptr;
        }
        
        // addID function modified from class exampple
        void addID(int new_id) {
            if(head == nullptr) { //insert when empty?
                Node *new_node = new Node{new_id, nullptr};
                head = new_node;
            
            } else if(new_id < head->id) { //insert before head
                Node *new_node = new Node{new_id, head};
                head = new_node;

            } else { //insert in the middle
                //walk to find the right spot for the new_id
                Node *previous = find_previous_node(new_id);
                //now insert the id!
                Node *new_node = new Node{new_id, previous->next};
                previous->next = new_node;
            }
        }
        
        // crude way of finding element using position
        void getID(int i) {
            struct Node *record = head;
            while(i > 1) {
                record = record->next;
                i--;
            }
            cout << record->id << endl;
        }
        
        // deleteID function using precise_search
        void deleteID(int i) {
            Node *ptr = precise_search(i);
            if(ptr == NULL) {
                cout << "No list containing ID: " << i << endl;
            }
            if(ptr == head) {
                head = ptr->next;
                return;
            }
            Node *current = head;
            Node *prev = head;
            
            while(current) {
                if(current == ptr) {
                    prev->next = current->next;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
        
        void mass_addID(int i) {
            int new_id;
            
            while(i > 0){
                cout << "Enter ID: ";
                cin >> new_id;
                addID(new_id);
                i--;
            } 
        }
        
        // basic display list function
        void display() {
            Node *record = head;
            if(record == nullptr){
                cout <<"The list is empty" << endl;
            }
            
            while(record) {
                cout << record->id << " ";
                record = record->next;
            }
        }
        
};   