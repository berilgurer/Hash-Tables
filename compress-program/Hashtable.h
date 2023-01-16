#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class HashedObj>
class HashTable
{
    public:

        HashTable<HashedObj>(const HashedObj & notFound, int size = 4096) //Construct the hash table
            : ITEM_NOT_FOUND(notFound), hashArray(size), currentSize(0)
        {
            for (int i = 0; i < hashArray.size(); i++)
            {
                hashArray[i].element = ITEM_NOT_FOUND; //give default ITEM_NOT_FOUND value for all
            }
        }
        HashTable(const HashTable & rhs ) // copy constructor
                      : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ),
                        hashArray(rhs.my_array), currentSize(rhs.currentSize){}
        bool hashtableFull(); //checks availability in hashtable
        void insert(const HashedObj & x, int &y); // Insert item x into the hash table
        int find(const HashedObj & x); // Find item x in the hash table

    private:

        struct HashEntry //struct of the templated object
        {
            HashedObj element; //our object
            int key;           //our key for integer value
            HashEntry(const HashedObj &e = HashedObj(), int i = 0): element(e), key(i) {} //struct constructor
        };
        int findPos(const HashedObj & x); // Return the position where the search for x terminates.
        bool isActive (int & currentPos, const HashedObj & x) const; // Return true if currentPos exists and is active
        vector<HashEntry> hashArray; //hashtable vector
        int currentSize; // # of elements
        const HashedObj ITEM_NOT_FOUND;
};




