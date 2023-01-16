
#include <iostream>
#include <vector>
#include "Hashtable.h"
using namespace std;

template <class HashedObj>
bool HashTable<HashedObj>::hashtableFull() //checks availability in hashtable
{
    if (currentSize + 1 >= hashArray.size())
        return true;
    else
        return false;
}

template <class HashedObj>
void HashTable<HashedObj>::insert(const HashedObj & x, int &y)
{
    int currentPos = findPos(x);
    if (isActive(currentPos, x)){ // If the item is already present, then do nothing
        return;
    }
    else{ // Insert item x into the hash table.
        hashArray[currentPos].element = x;
        hashArray[currentPos].key = y;
        currentSize++;
    }
}

template <class HashedObj> // Find item x in the hash table
int HashTable<HashedObj>::find(const HashedObj & x){
    int currentPos = findPos(x);
    if (isActive(currentPos, x))
    {
        return hashArray[currentPos].key; // Return the matching item
    }
    else{
        return 0; //if not found
    }
}

template <class HashedObj> // Return true if currentPos exists and is active
bool HashTable<HashedObj>::isActive(int & currentPos, const HashedObj & x) const
{
    return (hashArray[currentPos].element == x);
}

template <class HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj & x) //Method that performs linear probing
{
    int p = (hash<HashedObj>{}(x)) % (hashArray.size());

    while (hashArray[p].element != ITEM_NOT_FOUND && hashArray[p].element != x)
    { // Return the position where the search for x terminates.    
        p++; // increment the table position
        if (p >= hashArray.size())
        {
            p -= hashArray.size();
        }
    }
    return p;
}
