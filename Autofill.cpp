#include "Autofill.h"

void AutoFillTrie::autocomplete(TrieNode *node, string prefix,
                                vector<string> &results) {
  if (node->isEndOfWord) {
    results.push_back(prefix);
  }
  for (auto &pair : node->children) {
    autocomplete(pair.second, prefix + pair.first, results);
  }
}

void AutoFillTrie::insert(string word) {
  TrieNode *node = root;
  for (char ch : word) {
    if (node->children.find(ch) == node->children.end()) {
      node->children[ch] = new TrieNode();
    }
    node = node->children[ch];
  }
  node->isEndOfWord = true;
}

vector<string> AutoFillTrie::search(string prefix) {
  TrieNode *node = root;
  vector<string> results;
  for (char ch : prefix) {
    if (node->children.find(ch) == node->children.end()) {
      return results;
    }
    node = node->children[ch];
  }
  autocomplete(node, prefix, results);
  return results;
}
