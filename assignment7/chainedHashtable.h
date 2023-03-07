#pragma once

#include<string>
#include<list>

using namespace std;

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int,  string>> table[hashGroups];

    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string name);
        void removeItem(int key);
        void printTable();
};