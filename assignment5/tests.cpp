#include <iostream>

#include "auto_sort.cpp"

using namespace std;

int main() {
    
    Auto_Sort *my_auto_sort = new Auto_Sort();
    
    // display empty list 
    cout << "empty list" << endl;
    my_auto_sort->display();
    cout << "" << endl;
    
    // add one item to element and print
    cout << "single element insert" << endl;
    my_auto_sort->addID(10);
    my_auto_sort->display();
    cout << "" << endl;
    
    // add another larger element to list and print
    cout << "second element" << endl;
    my_auto_sort->addID(11);
    my_auto_sort->display();
    cout << "" << endl;
    
    // add a smaller element to list and print
    cout << "third lesser than element" << endl;
    my_auto_sort->addID(8);
    my_auto_sort->display();
    cout << "" << endl;
    
    // mass add two elements one smaller one larger and print (4 and 15)
    cout << "mass insert two elements at once (4 and 15)" << endl;
    my_auto_sort->mass_addID(2);
    my_auto_sort->display();
    cout << "" << endl;
    
    // add duplicate element and print
    cout << "duplicate element" << endl;
    my_auto_sort->addID(10);
    my_auto_sort->display();
    cout << "" << endl;
    
    // remove element (non-duplicate) and print
    cout << "remove non dupe element" << endl;
    my_auto_sort->deleteID(8);
    my_auto_sort->display();
    cout << "" << endl;
    
    // remove duplicate and print
    cout << "remove duplicate element (10)" << endl;
    my_auto_sort->deleteID(10);
    my_auto_sort->display();
    cout << "" << endl;
    
    // find element in 3rd position and print
    cout << "find element in 3rd pos" << endl;
    my_auto_sort->getID(3);
    my_auto_sort->display();
    cout << "" << endl;
    
    return 0;
}