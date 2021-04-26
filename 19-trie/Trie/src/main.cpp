#include <iostream>
#include <string>
#include <vector>
#include "trie.h"

int main()
{
    Trie myTrie;
    std::vector<std::string> words{"answer", "any", "a", "bye", 
        "by", "the", "there", "their"};

    for (const std::string &word : words)
    {
        myTrie.insert(word);
    }

    std::cout << "the = " << myTrie.search("the") << '\n';
    std::cout << "these = " << myTrie.search("these") << '\n';
    std::cout << "th = " << myTrie.search("th") << '\n';
    std::cout << "th = " << myTrie.startsWith("th") << '\n';
    std::cout << "an = " << myTrie.startsWith("an") << '\n';

    return 0;
}