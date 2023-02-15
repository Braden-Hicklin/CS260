#include <iostream>

#include "list.cpp"

using namespace std;

int main()
{
    Linked_List linkl;

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
                linkl.addID(j);
                break;
            case(2):
                cout << 
                "Enter the ID you'd like to be placed in the middle: " << endl;
                cin >> j;
                linkl.insertID(j);
                break;
            case(3):
                cout << "Enter the ID you'd like to be removed: " << endl;
                cin >> j;
                linkl.deleteID(j);
                break;
            case(4):
                linkl.display();
                cout << "" << endl;
                break;
            case(5):
                cout << 
                "Enter the position of the ID you'd like to display: " << endl;
                cin >> j;
                linkl.getID(j);
            case(6):
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }
    }
	return 0;
}