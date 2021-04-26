#include "hashset.h"

/**
 * @brief Construct a new Hash Set:: Hash Set object
 * 
 * @param capacity  initial number of buckets
 */
HashSet::HashSet(int capacity)
{
    this->mSize = 0; 
    this->mCapacity = capacity; 
    this->mElements = new std::list<int>[this->mCapacity];
}

/**
 * @brief Destroy the Hash Set:: Hash Set object
 * 
 */
HashSet::~HashSet()
{
    delete [] this->mElements;
}

/**
 * @brief Determine if key is in the hash set
 * 
 * @param key    a possible key in the hash set
 * @return true  key is in the hash set
 * @return false key is not in the hash set
 */
bool HashSet::contains(int key) const // search
{
    // determine index based on the key 
    int index = this->getIndex(key);

    // find the key in the hash set
    for (auto val : this->mElements[index])
    {
        if (val == key)
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief Add a new key in the hash set. Hash set only
 *        allows unique keys.
 * 
 * @param key  value of key to add in the hash set
 */
void HashSet::add(int key)
{
    // determine the current load factor
    float loadFactor = (mSize + 1) / static_cast<float>(this->mCapacity);

    // if the load factor is greater than 1.0, rehash
    if (loadFactor > 1.0f)
    {
        this->rehash();
    }

    // determine index based on the key 
    int index = this->getIndex(key);

    // add key only if it is not in the hash set
    if (!this->contains(key))
    {
        // add key to the correct linked list in the hash set
        this->mElements[index].push_back(key);
        // increment size of the hash set
        ++this->mSize;
    }
}

/**
 * @brief Clear the hash set 
 * 
 */
void HashSet::clear()
{
    // Go through each linked list in the array
    for (int i = 0; i < this->mCapacity; ++i)
    {
        // delete all the nodes in the linked list
        this->mElements[i].clear();
    }
}

/**
 * @brief Returns conversion of hash set in string
 * 
 * @return string  hash set in string
 */
string HashSet::toString() const
{
    ostringstream ostr;

    for (int i = 0; i < this->mCapacity; ++i)
    {
        ostr << i << ": ";
        for (const auto &val : this->mElements[i])
        {
            ostr << val << ' ';
        }
        ostr << '\n';
    }

    return ostr.str();
}

/**
 * @brief Returns true if hash set is empty, false otherwise
 * 
 * @return true  hash set is empty
 * @return false hash set is not empty
 */
bool HashSet::isEmpty() const
{
    return this->mSize == 0;
}

/**
 * @brief Remove a key from the hash set
 * 
 * @param key 
 */
void HashSet::remove(int key)
{
    // using the key, find the index in the array of linked list
    int index = this->getIndex(key);

    // loop through each node in the linked list
    for (auto it = this->mElements[index].begin(); it != this->mElements[index].end(); ++it)
    {
        if (*it == key)
        {
            this->mElements[index].erase(it);
        }
    }
}

/**
 * @brief Move current hash set to a bigger one
 * 
 */
void HashSet::rehash()
{
    // double the current capacity
    int prevCapacity = mCapacity;
    this->mCapacity *= 2;

    // create a bigger array
    std::list<int> *biggerArray;
    biggerArray = new std::list<int>[this->mCapacity];

    // move everything in mElements to biggerArray
    for (int i = 0; i < prevCapacity; ++i)
    {
        // go through each node in the linked list
        while (!this->mElements[i].empty())
        {
            int key = this->mElements[i].front();
            this->mElements[i].pop_front();

            // recompute it's hashcode and index and
            int newIndex = this->getIndex(key);
            // position it in the right location in the new hash set
            biggerArray[newIndex].push_back(key);
        }
    }

    // delete the old array of linked list
    delete [] this->mElements;

    // assign mElements to the new bigger array
    this->mElements = biggerArray;
    biggerArray = nullptr;
}

/**
 * @brief Return the current number of elements in the hash set
 * 
 * @return int 
 */
int HashSet::size() const
{
    return this->mSize;
}

/**
 * @brief Maps key to an index in the hash set array
 * 
 * @param key   key value
 * @return int  valid index in the array of list
 */
int HashSet::getIndex(int key) const
{
    // h(hashCode) = ((a * hashCode + b) % p) % N
    int a = 3, b = 7;
    int index = ((a * hashCode(key) + b) % P) % this->mCapacity; // compression
    return index;
}

/**
 * @brief Hashing function maps key to hash code
 * 
 * @param key   key to map to hash code
 * @return int  hash code of the key
 */
int hashCode(int key)
{
    int hashVal = 5381;
    hashVal = 33 * hashVal + key;
    return hashVal;
}

/**
 * @brief Hashing function maps key to hash code
 * 
 * @param key  key to map to hash code
 * @return int hash code of the key
 */
int hashCode(string key) 
{
    // Set hashVal to 0
    // Set index to 0
    // For index is less than number of characters in key
        // hashVal = (127 * hashVal + key[index]) mod P
    // Return hashVal
    return 0; // fixme
}