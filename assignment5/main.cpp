#include <iostream>

#include "auto_sort.cpp"

using namespace std;

int main()
{
    Auto_Sort sort;
    
    // main menu loop    
    int choice, new_value = 0;
    while(choice != 6) {
        cout << "========= Menu =========" << endl;
        cout << "=      1. Add ID       =" << endl;
        cout << "=      2. Mass Add ID  =" << endl;
        cout << "=      3. Delete ID    =" << endl;
        cout << "=      4. List IDs     =" << endl;
        cout << "=      5. Search Pos   =" << endl;
        cout << "=      6. Quit         =" << endl;
        cout << "========================" << endl;
        cin >> choice;
        
        switch(choice) {
            case(1):
                cout << "Enter the ID you'd like to add: " << endl;
                cin >> new_value;
                sort.addID(new_value);
                break;
            case(2):
                cout << "How many ID's would you like to enter?: " << endl;
                cin >> new_value;
                sort.mass_addID(new_value);
                break;
            case(3):
                cout << "Enter the ID you'd like to be removed: " << endl;
                cin >> new_value;
                sort.deleteID(new_value);
                break;
            case(4):
                sort.display();
                cout << " " << endl;
                break;
            case(5):
                cout << 
                "Enter the position of the ID you'd like to display: " << endl;
                cin >> new_value;
                sort.getID(new_value);
            case(6):
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }
        
    }
	return 0;
}

