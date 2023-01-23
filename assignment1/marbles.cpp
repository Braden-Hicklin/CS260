#include <iostream>

using namespace std;

class Marble
{
    public:
        string color;
        string pattern;
        string size;
};

typedef struct node{
    Marble marble;
    struct node *next;
} marbleBag;

int menu(int x, marbleBag *head);
Marble* createNewMarble(string clr, string patt, string sz);
marbleBag* add2bag(marbleBag *head, Marble newMarble);
void print_list(marbleBag *head);

int main() {
    int menuChoice;
    marbleBag *head = NULL;

    menu(menuChoice, head);
    

    return 0;
}

int menu(int x, marbleBag *head){
    
    string a, b, c;
    marbleBag *current = head;

    while(x != 3){

        cout << "Welcome to the Marble Program" << endl;
        cout << "   Select a menu option" << endl;
        cout << "   1. List Marbles" << endl;
        cout << "   2. Create Marble" << endl;
        cout << "   3. Quit Game" << endl;
        cin >> x;
        
        switch(x){
            case 1:
                print_list(current);
                break;
            case 2:
                cout << "Please Enter the color of the Marble" << endl;
                cin >> a;
                cout << "Please Enter the pattern of the Marble" << endl;
                cin >> b;
                cout << "Please enter the size of the Marble" << endl;
                cin >> c;
                Marble newMarble = createNewMarble(a, b, c);
                current = add2bag(current, newMarble);
                break;
            case 3:
                break;
        }
    }
}

Marble createNewMarble(string clr, string patt, string sz){
    Marble* newMarble = (Marble*) malloc(sizeof(Marble));

    newMarble->color = clr;
    newMarble->pattern = patt;
    newMarble->size = sz;

    return(newMarble);
}

marbleBag* add2bag(marbleBag *head, Marble newMarble){
    marbleBag *newBag = (marbleBag*) malloc(sizeof(marbleBag));
    if (!newBag) return NULL;

    // Adds item to the front of the marbleBag and moves to next node
    newBag->marble = newMarble;
    newBag->next = head;
    
    // Returns the marbleBag 
    return(newBag);
} 

void print_list(marbleBag *head)
{
    marbleBag *current = head;

    // If the list is empty this prints
    if (!current) puts("Printing... it's an empty list!");
    else{
        while (current != NULL)
        {
            cout << "Marble Color: " << current->marble.color << endl;
            cout << "Marble Pattern: " << current->marble.pattern << endl;
            cout << "Marble Size: " << current->marble.size << endl; 
        }
    }
    return;
}
 




