#include <iostream>
#include "chainedHashtable.cpp"
#include "simpleHashTable.cpp"

using namespace std;

int main() {
    
    // Chained Hashtable 
    HashTable HT;

    if(HT.isEmpty()) {
        cout << "Correct answer." << endl;
    } else {
        cout << "Error in the code." << endl;
    }

    //Inserts some random nums and names into hashtable.
    //Due to the use of modulo op only the last number matters for which list
    //they will be placed into.

    HT.insertItem(103, "John");
    HT.insertItem(135, "Michael");
    HT.insertItem(312, "Gabriel");
    HT.insertItem(205, "Uriel");
    HT.insertItem(422, "Peter");
    HT.insertItem(811, "Judas");
    HT.insertItem(811, "Judas 2"); //Tests to see if value was overriden properly
    
    HT.printTable();

    HT.removeItem(312);
    HT.removeItem(135);
    HT.removeItem(100); //Tests if remove function can handle non existent key

    if(HT.isEmpty()) {
        cout << "Error in the code." << endl;
    } else {
        cout << "Correct answer." << endl;
    }

    // Doubly linked hashtable/hashmap
    HashMap HM;
    HM.add(4, 5);
    HM.add(3, 5);
    HM.add(2, 4);
    HM.add(8, 2);
    HM.add(8, 1); //Add duplicate key

    HM.search(4);
    HM.search(3);
    HM.search(1); //Non-existent key
    
    HM.remove(4);
    HM.search(4); //Recently removed key
    HM.remove(1); //Non-existent key

    return 0;
}