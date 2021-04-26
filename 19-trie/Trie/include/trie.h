/**
 * @file trie.h
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief 
 * @version 0.1
 * @date 2021-04-26
 * @source Adapted from https://www.geeksforgeeks.org/trie-insert-and-search/
 * 
 */

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <cctype>

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    // isWord is true if the node representa a word
    bool isWord;

    TrieNode()
    {
        isWord = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            children[i] = nullptr;
        }
    }
};


class Trie
{
public:
    Trie();
    ~Trie();

    // Inserts a word into the trie
    void insert(std::string word);
    // Returns if the word is in the trie
    bool search(std::string word) const;
    // Returns if there is any word in the trie 
    // that strats with the given prefix
    bool startsWith(std::string prefix) const ;
    // clears Trie
    void clear();

private:
    TrieNode *mRoot;

    void clear(TrieNode *ptr);
    int getIndex(char letter) const;
};

#endif