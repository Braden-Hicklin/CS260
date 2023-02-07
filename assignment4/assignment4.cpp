#include <iostream>

using namespace std;

// linked list 
struct node {
    int id;
    struct node * next;
};

// initializes head
node *head = NULL;

// lazy search through the list
struct node *searchList(int i){
    if(head == NULL) return head;
    node *current = head;
    node *prev = head;
    // returns pointer to element whose id is less than or equal to input
    // best used for basic non-destructive functions (ie creating node)
    while(current){
        if(current->id == i) return current;
        if(current->id > i) return prev;
        prev = current;
        current = current->next;
    }
}

// precise search through the list
struct node *searchListEq(int i){
    if(head == NULL) return head;
    node *current = head;
    node *prev = head;
    // returns pointer to element whose id is equal to input 
    // best used for exact ids (ie deleting)
    while(current){
        if(current->id == i) return current;
        prev = current;
        current = current->next;
    }
}

// creates a new node at the end of the list
void addID(int i) {
    node *newNode = new node;
    newNode->id = i;
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
void insertID(int i) {
    node *ptr = searchList(i);
    node *newNode = new node;
    newNode->id = i;
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
void getID(int i) {
    struct node *record = head;
    while(i > 1) {
        record = record->next;
        i--;
    }
    cout << record->id << endl;
}

// removes specific node based on id
void deleteID(int i) {
    node *ptr = searchListEq(i);
    if(ptr == NULL) {
        cout << "No list containing ID: " << i << endl;
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

int main()
{
    int i, j = 0;
    while(i != 6) {
        cout << "========= Menu =========" << endl;
        cout << "=      1. Add ID       =" << endl;
        cout << "=      2. Insert ID    =" << endl;
        cout << "=      3. Delete ID    =" << endl;
        cout << "=      4. List IDs     =" << endl;
        cout << "=      5. Search Pos   =" << endl;
        cout << "=      6. Quit         =" << endl;
        cout << "========================" << endl;
        cin >> i;
        
        switch(i) {
            case(1):
                cout << "Enter the ID you'd like to add: " << endl;
                cin >> j;
                addID(j);
                break;
            case(2):
                cout << 
                "Enter the ID you'd like to be placed in the middle: " << endl;
                cin >> j;
                insertID(j);
                break;
            case(3):
                cout << "Enter the ID you'd like to be removed: " << endl;
                cin >> j;
                deleteID(j);
                break;
            case(4):
                display();
                cout << "" << endl;
                break;
            case(5):
                cout << 
                "Enter the position of the ID you'd like to display: " << endl;
                cin >> j;
                getID(j);
            case(6):
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }
        
    }
	return 0;
}
