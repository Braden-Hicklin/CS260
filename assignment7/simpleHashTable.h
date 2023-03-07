#pragma once

#include<string>
#include<list>

using namespace std;

struct node_hash {
    int val, key;
    node_hash* left;
    node_hash* right;
};

class HashMap {
    private:
        const int hashGroups = 25;
        node_hash **hashTable, **top;

    public:
        HashMap() {
            hashTable = new node_hash*[hashGroups];
            top = new node_hash*[hashGroups];
            for(int i = 0; i < hashGroups; i++) {
                hashTable[i] = NULL;
                top[i] = NULL;
            }
        }

        ~HashMap() {
            delete[] hashTable;
        }
        int hashFunction(int key);
        void search(int key);
        void remove(int key);
        void add(int key, int val);
};