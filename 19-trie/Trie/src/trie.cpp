#include "trie.h"

Trie::Trie()
{
    mRoot = new TrieNode();
}

int Trie::getIndex(char letter) const
{
    return tolower(letter) - 'a';
}

// Inserts a word into the trie
void Trie::insert(std::string word)
{
    TrieNode *ptr = mRoot;

    for (char letter : word)
    {
        int index = getIndex(letter);
        if (ptr->children[index] == nullptr)
        {
            ptr->children[index] = new TrieNode();
        }

        ptr = ptr->children[index];
    }

    ptr->isWord = true;
}

// Returns if the word is in the trie
bool Trie::search(std::string word) const
{
    TrieNode *ptr = mRoot;

    for (char letter : word)
    {
        int index = getIndex(letter);
        if (ptr->children[index] == nullptr)
        {
            return false;
        }

        ptr = ptr->children[index];
    }

    return (ptr != nullptr && ptr->isWord);
}

// Returns if there is any word in the trie 
// that strats with the given prefix
bool Trie::startsWith(std::string prefix) const
{
    TrieNode *ptr = mRoot;

    for (char letter : prefix)
    {
        int index = getIndex(letter);
        if (ptr->children[index] == nullptr)
        {
            return false;
        }

        ptr = ptr->children[index];
    }

    return (ptr != nullptr);
}

Trie::~Trie()
{
    clear();
    delete [] mRoot;
}

void Trie::clear()
{
    clear(mRoot);
}

void Trie::clear(TrieNode *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (ptr->children[i] != nullptr)
        {
            clear(ptr->children[i]);
            delete [] ptr->children[i];
            ptr->children[i] = nullptr;
        }
    }
}
