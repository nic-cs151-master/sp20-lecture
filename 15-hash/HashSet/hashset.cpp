#include "hashset.h"

HashSet::HashSet()
{
    mSize = 0; 
    mCapacity = 10; 
    mElements = new std::list<int>[mCapacity];
}

HashSet::~HashSet()
{
    delete [] mElements;
}

bool HashSet::contains(int key) const // search
{
    int index = getIndex(key);

    for (auto val : mElements[index])
    {
        if (val == key)
        {
            return true;
        }
    }

    return false;
}

void HashSet::add(int key)
{
    float loadFactor = (mSize + 1) / static_cast<float>(mCapacity);

    if (loadFactor > 1.0f)
    {
        rehash();
    }

    int index = getIndex(key);

    for (auto val : mElements[index])
    {
        if (val == key)
        {
            return;
        }
    }

    mElements[index].push_back(key);
    ++mSize;
}

void HashSet::clear()
{
    for (int i = 0; i < mCapacity; ++i)
    {
        mElements[i].clear();
    }
}

string HashSet::toString() const
{
    ostringstream ostr;

    for (int i = 0; i < mCapacity; ++i)
    {
        ostr << i << ": ";
        for (const auto &val : mElements[i])
        {
            ostr << val << ' ';
        }
        ostr << '\n';
    }

    return ostr.str();
}

bool HashSet::isEmpty() const
{
    return mSize == 0;
}

void HashSet::remove(int key)
{
    int index = getIndex(key);

    // for (std::list<int>::iterator it = mElements[index].begin(); )
    for (auto it = mElements[index].begin(); it != mElements[index].end(); ++it)
    {
        if (*it == key)
        {
            mElements[index].erase(it);
        }
    }
}

void HashSet::rehash()
{
    mCapacity *= 2;

    // create a bigger array
    std::list<int> *biggerArray;
    biggerArray = new std::list<int>[mCapacity];

    // move everything in mElements to biggerArray
    for (int i = 0; i < (mCapacity / 2); ++i)
    {
        while (!mElements[i].empty())
        {
            int key = mElements[i].front();
            mElements[i].pop_front();

            int newIndex = getIndex(key);
            biggerArray[newIndex].push_back(key);
        }
    }

    // delete mElements
    delete [] mElements;

    // assign mElements to the new bigger array
    mElements = biggerArray;
    biggerArray = nullptr;
}

int HashSet::size() const
{
    return mSize;
}

int HashSet::getIndex(int key) const
{
    // h(hashCode) = ((a * hashCode + b) % p) % N
    int a = 3, b = 7;
    int index = ((a * hashCode(key) + b) % P) % mCapacity; // compression
    return index;
}

int hashCode(int key)  // hash function
{
    return key;
}


int hashCode(string key) 
{
    return 1;
}