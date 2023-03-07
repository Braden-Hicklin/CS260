#include <iostream>
#include "chainedHashtable.h"


bool HashTable::isEmpty() const { 
    int sum{};
    
    for(int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if(!sum) {
        return true;
    }
        return false;
}

//Hash function that stores int using the last digit in key
int HashTable::hashFunction(int key) {
    return key % hashGroups; //Key: 905, this fun => 5
}

void HashTable::insertItem(int key, string name) {
    int hashValue = hashFunction(key); //Need corresponding value to key
    auto& cell = table[hashValue]; //List that key value will be placed into
    auto bItr = begin(cell); //Iterate to the beginning
    bool keyExists = false; //Check for key existence, assume false for machine sake
    
    //Validates keyExists 
    for(; bItr != end(cell); bItr++) {
        if(bItr->first==key) {
            keyExists = true; //Yes key exists
            bItr->second = name; //Change name in key
            cout << "[WARNING] Key exists. Value replaced." << endl;
            break;
        }
    }
    
    //Key doesn't exist, insert key
    if(!keyExists) {
        cell.emplace_back(key, name);
    }

    return;
}

// Mirrors insert function
void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key); //Need corresponding value to key
    auto& cell = table[hashValue]; //List that key value will be placed into
    auto bItr = begin(cell); //Iterate to the beginning
    bool keyExists = false; //Check for key existence, assume false for machine sake
    
    //Validates keyExists 
    for(; bItr != end(cell); bItr++) {
        if(bItr->first==key) {
            keyExists = true; //Yes key exists
            //Avoids collision by placing new iterator in next position since it no longer exists
            bItr = cell.erase(bItr);
            cout << "Item removed." << endl;
            break;
        }
    }

    // Non existent key
    if(!keyExists) {
        cout << "[WARNING] Item not found." << endl;
    }

    return;
}

void HashTable::printTable() {
    for(int i{}; i < hashGroups; i++) {
        if(table[i].size() == 0) continue; //If the table is empty

        auto bItr = table[i].begin();
        for(; bItr != table[i].end(); bItr++) {
            cout << "[INFO] Key: " << bItr->first << " Name: " << bItr->second << endl;
        }
    }
    return;
}
