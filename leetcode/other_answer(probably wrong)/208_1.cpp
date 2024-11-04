#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Trie {
private:
  unordered_set<string> ps;
  unordered_set<string> ws;
public:
  Trie() {
    
  }
    
  void insert(string word) {
    ws.insert(word);
    for(int i = 1; i <= word.size(); i++) {
      ps.insert(word.substr(0, i));
    }
  }
    
  bool search(string word) {
    if(ws.count(word))
      return true;
    return false;
  }
    
  bool startsWith(string prefix) {
    if(ps.count(prefix))
      return true;
    return false;
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
