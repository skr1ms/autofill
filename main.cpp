#include "Autofill.h"

int main() {
  AutoFillTrie trie;
  vector<string> dictionary = {"youtube", "myanimelist", "skillfactory"};
  for (string word : dictionary) {
    trie.insert(word);
  }

  while (true) {
    string prefix;
    cout << "Введите префикс для автодополнения: ";
    cin >> prefix;

    vector<string> suggestions = trie.search(prefix);
    if (!suggestions.empty()) {
      cout << "Возможные слова:" << endl;
      for (string suggestion : suggestions) {
        cout << suggestion << endl;
      }
    } else {
      cout << "Нет слов, начинающихся с этого префикса." << endl;
    }
  }

  return 0;
}
