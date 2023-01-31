#include <iostream>
using namespace std;

// Node struct
struct Node {
    int num;
    int pos;
    Node* next;
    Node(int i)
    {
        num = i;
        next = NULL;
    }
};

// List struct
struct Queue {
    Node *front, *rear;
    Queue() { front = rear = NULL; }
    
    // enqueue method
    void insertQueue(int i)
    {
        int j = 1;
        // Creates a new node 
        Node* current = new Node(i);
        // If queue is empty num is both the front and rear
        if (rear == NULL) {
            front = rear = current;
            return;
        }
 
        // Insert into the rear
        rear->next = current;
        rear = current;
    }
 
    // dequeue method
    void removeQueue()
    {
        if (front == NULL)
            return;
 
        // Stores front and moves to next num
        Node* current = front;
        front = front->next;
 
        // If all items have been removed then set rear to NULL
        if (front == NULL)
            rear = NULL;
 
        delete (current);
    }
    
    // print method
    void printQueue()
    {
        int j = 1;
        
        // If queue is empty this is printed
        if (!front) puts("The Queue is currently empty!");
        
        // Cycles through the list, printing all items
        else{
            cout<< "-------- Queue --------" << endl;
            // While loop that prints each num with its associated position
            while (front != NULL)
            {
                cout << "List Item " << (j) << ": " << (front->num) << endl;
                front = front->next;
                j++;
            }
        }
        return;
    }
};
 

int main()
{
    Queue queue;
    
    queue.insertQueue(10);
    queue.insertQueue(20);
    queue.insertQueue(30);
    queue.insertQueue(40);
    queue.insertQueue(50);
    queue.printQueue();
    
    queue.removeQueue();
    queue.printQueue();
    
    return 0;
}
