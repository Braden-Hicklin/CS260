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
        Node *precise_search(int new_id){
            if(head == NULL) return head;
            Node *current = head;
            Node *prev = head;
            // returns pointer to element whose id is equal to input 
            while(current){
                if(current->id == new_id) return current;
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
        void add_id(int new_id) {
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
        void get_pos(int new_id) {
            Node *record = head;
            // steps through list
            while(new_id > 1) {
                record = record->next;
                new_id--;
            }
            cout << record->id << endl;
        }
        
        // search for specific ID
        void pull_id(int new_id) {
            Node *ptr = precise_search(new_id);
            if(ptr == NULL) {
                cout << "No list containing ID: " << new_id << endl;
            }

            // needed to find element at head
            if(ptr == head) {
                cout << "ID: " << new_id << " was found in the list" << endl;
                return;
            }
            Node *current = head;
            Node *prev = head;

            // search for element not at head
            while(current) {
                if(current == ptr) {
                    cout << "ID: " << new_id << " was found in the list" << endl;
                    return;
                } 
                prev = current;
                current = current->next;
            }
        }

        // deleteID function using precise_search
        void delete_id(int new_id) {
            Node *ptr = precise_search(new_id);
            if(ptr == NULL) {
                cout << "No list containing ID: " << new_id << endl;
            }
            
            // needed to delete first element
            if(ptr == head) {
                head = ptr->next;
                cout << "ID: " << new_id << " has been deleted." << endl;
                return;
            }
            Node *current = head;
            Node *prev = head;
            
            // delete element not found at head
            while(current) {
                if(current == ptr) {
                    prev->next = current->next;
                    cout << "ID: " << new_id << " has been deleted." << endl;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
        
        // add multiple ids using add_id function
        void mass_add_id(int new_num) {
            int new_id;
            
            while(new_num > 0){
                cout << "Enter ID: ";
                cin >> new_id;
                add_id(new_id);
                new_num--;
            } 
        }
        
        // display ids
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
