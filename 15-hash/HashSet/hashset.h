#ifndef HASHSET_H
#define HASHSET_H

#include <string>
#include <sstream>
#include <list>

using std::ostringstream;
using std::string;

const int P = 16908799;

class HashSet
{
public:
    HashSet(int capacity=10);
    ~HashSet();

    void add(int key);
    void clear();
    bool isEmpty() const;
    bool contains(int key) const;
    void remove(int key);
    int size() const;
    string toString() const;

private:
    std::list<int> *mElements; // hash set, hash table
    int mSize;
    int mCapacity;
    int getIndex(int key) const;
    void rehash();
};

int hashCode(int key);
int hashCode(string key);

#endif