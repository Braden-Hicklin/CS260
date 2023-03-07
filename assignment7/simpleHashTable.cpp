#include <iostream>
#include "simpleHashTable.h"

int HashMap::hashFunction(int key) {
    return key % hashGroups;
}

void HashMap::search(int key) {
    int hashValue = hashFunction(key);
    bool flag = false;
    node_hash* value = hashTable[hashValue];

    if(value != NULL) {
        while(value != NULL) {
            if(value->key == key) {
                flag = true;
            }
            if(flag) {
                cout << "Value found at key " << key << ": " << value->val << endl;
            }
            value = value->left;
        }
        if(!flag) cout << "No Value found at key " << key << endl;
    }
}

void HashMap::remove(int key) {
    int hashValue = hashFunction(key);
    node_hash* value = hashTable[hashValue];
    if(value->key != key || value == NULL) {
        cout << "Couldn't find any value at key " << key << endl;
        return;
    }

    while(value != NULL) {
        if(value->left == NULL) {
            if(value->right == NULL) {
                hashTable[hashValue] = NULL;
                top[hashValue] = NULL;
                delete value;
                break;
            } else {
                top[hashValue] = value->right;
                top[hashValue]->left = NULL;
                delete value;
                value = top[hashValue];
            }
        }
        value = value->left;
    }
    cout << "Value was successfully removed at key " << key << endl;
}

void HashMap::add(int key, int val) {
    int hashValue = hashFunction(key);
    node_hash* value = hashTable[hashValue];

    // if key has no value stored
    if (value == NULL) {
        // creating new node
        value = new node_hash;
        value->val = val;
        value->key = key;
        value->left = NULL;
        value->right = NULL;
        hashTable[hashValue] = value;
        top[hashValue] = value;
    }

    // if some values are present
    else {
        // traversing till the end of
        // the list
        while (value != NULL)
            value = value->left;

        // creating the new node
        value = new node_hash;
        value->val = val;
        value->key = key;
        value->left = NULL;
        value->right = top[hashValue];
        top[hashValue]->left = value;
        top[hashValue] = value;
    }
    cout << "Value " << val << " was successfully"
            " added at key " << key << endl;

}