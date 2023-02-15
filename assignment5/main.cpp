#include <iostream>

#include "auto_sort.cpp"

using namespace std;

int main()
{
    
    Auto_Sort sort;
    
    // main menu loop    
    int choice, new_value = 0;
    while(choice != 7) {
        cout << "========== Menu ==========" << endl;
        cout << "=       1. Add ID        =" << endl;
        cout << "=       2. Mass Add ID   =" << endl;
        cout << "=       3. Search For ID =" << endl;
        cout << "=       4. List IDs      =" << endl;
        cout << "=       5. Search Pos    =" << endl;
        cout << "=       6. Delete ID     =" << endl;
        cout << "=       7. Quit          =" << endl;
        cout << "==========================" << endl;
        cin >> choice;
        
        switch(choice) {
            case(1):
                cout << "Enter the ID you'd like to add: " << endl;
                cin >> new_value;
                sort.add_id(new_value);
                break;
            case(2):
                cout << "How many ID's would you like to enter?: " << endl;
                cin >> new_value;
                sort.mass_add_id(new_value);
                break;
            case(3):
                cout << "Enter the ID you're looking for: " << endl;
                cin >> new_value;
                sort.pull_id(new_value);
                break;
            case(4):
                sort.display();
                cout << " " << endl;
                break;
            case(5):
                cout << 
                "Enter the position of the ID you'd like to display: " << endl;
                cin >> new_value;
                sort.get_pos(new_value);
                break;
            case(6):
                cout << "Enter the ID you'd like to be removed: " << endl;
                cin >> new_value;
                sort.delete_id(new_value);
                break;
            case(7):
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }
    }
    
    return 0;
}

