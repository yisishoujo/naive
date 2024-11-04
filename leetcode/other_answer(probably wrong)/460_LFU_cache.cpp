#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

struct Node {
  int val;
  int freq;
  list<int>::iterator it; // position in freqm's list<int>
  Node(int x) : val(x), freq(1), it(nullptr) {}
};

class LFUCache {
private:
  unordered_map<int, Node> keym;
  list<int> keys; // order of keys
  unordered_map<int, list<int>::iterator> freqm;
  int cap;
  int len;
  list<int> remove;
public:
  LFUCache(int capacity) {
    cap = capacity - 1;
    len = 0;
  }
    
  int get(int key) {
    if(keym.find(key) == keym.end())
      return -1;
    update(key);
    return keym[key].val;
  }
    
  void put(int key, int value) {
    if(keym.find(key) != keym.end()) {
      keym[key].val = value;
      update(key);
      return;
    }
    if(len > cap) {
      rm();
    } else {  
      len++;
    }
    keym[key] = Node(value);
    keym[key].it = keys.insert(freqm[1], key); // always have freqm[1]
  }

  void update(int key) {
    int f = ++keym[key].freq;
    auto it = keym[key].it;

    if(freqm.find(f) == freqm.end()) { // unfinished
      if(keym[*next(it)].freq >= f) // too hard to maintain this freqm
        freqm[f] = freqm[f-1];
      if(keym[*prev(it)].freq < f-1) {
        if(f != 2) {
          freqm.erase(f-1);
        } else {
          
      }
    }
    
    }

    void rm() {
      auto temp = remove;
      remove++;
      keym.erase(*temp);
      keys.erase(temp);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LFUCache lc = LFUCache(2);
  lc.put(1, 1);
  cout << "get(1)" << lc.get(1) << endl;
  lc.put(2, 2);
  cout << "get(2)" << lc.get(2) << endl;
  lc.put(3, 3);
  cout << "get(2)" << lc.get(2) << endl;
  return 0;
}
