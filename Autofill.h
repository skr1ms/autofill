#ifndef AUTO_FILL_H
#define AUTO_FILL_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode *> children;
  bool isEndOfWord;

  TrieNode() { isEndOfWord = false; }
};

class AutoFillTrie {
private:
  TrieNode *root;

  void autocomplete(TrieNode *node, string prefix, vector<string> &results);

public:
  AutoFillTrie() { root = new TrieNode(); }

  void insert(string word);

  vector<string> search(string prefix);
};

#endif
