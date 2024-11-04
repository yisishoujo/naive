#include <iostream>
#include <string>
#include <map>

using namespace std;

// seems like what he wants // however perfomance is not good
// slightly worse than just use unordered_set

// char a-z, and just create all, then you can insert/search with a for loop and pointer operation
class Trie {
public:
  map<char, Trie*> mtn;
  bool wordend;
  Trie(bool w): wordend(w), mtn() {}
  Trie(char c, bool w, Trie* t): wordend(w), mtn({{c, t}}) {}
  
  Trie() {
    wordend = true;
  }

  Trie(string s) {
    int n = s.size();
    if(n == 0) {
      wordend = true;
      return;
    }
    Trie* root = new Trie();
    for(int i = n - 1; i > 0; i++) {
      root = new Trie(s[i], false, root);
    }
    wordend = false;
    mtn[s[0]] = root;
  }
 
  void insert(string word) {
    if(word.size() == 0) {
      wordend = true;
      return;
    }
    if(!mtn.count(word[0])) {
      mtn[word[0]] = new Trie(false);
    }
    mtn[word[0]]->insert(word.substr(1));
  }
    
  bool search(string word) {
    if(word.size() == 0)
      return wordend;
    if(!mtn.count(word[0]))
      return false;
    return mtn[word[0]]->search(word.substr(1));
  }
    
  bool startsWith(string prefix) {
    if(prefix.size() == 0)
      return true;
    if(!mtn.count(prefix[0]))
      return false;
    return mtn[prefix[0]]->startsWith(prefix.substr(1));
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  Trie t = Trie();
  t.insert("apple");
  t.search("apple");
  t.search("app");
  t.startsWith("app");

  return 0;
}
