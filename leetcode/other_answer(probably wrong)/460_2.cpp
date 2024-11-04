#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
  int val;
  int freq;
  Node *prev;
  Node *next; // next means larger freq
  Node() : val(0), freq(1), prev(nullptr), next(nullptr) {}
  Node(int x) : val(x), freq(1), prev(nullptr), next(nullptr) {}
  Node(int x, Node *p, Node *n) : val(x), freq(1), prev(p), next(n) {}
};

class LFUCache {
private:
  unordered_map<int, Node> keym;
  unordered_map<int, Node*> freqm;
  int cap;
  int len;
  int remove; // the key to remove
public:
  LFUCache(int capacity) {
    cap = capacity - 1;
    len = 0;
  }
    
  int get(int key) {
    if(keym.find(key) == keym.end())
      return -1;
    keym[key].freq++;
    update(key, 1);
    return keym[key].val;
  }
    
  void put(int key, int value) {
    if(keym.find(key) != keym.end()) {
      keym[key].val = value;
      keym[key].freq++;
      update(key, 1);
      return;
    }
    if(len > cap)
      keym.erase(remove);
    else  
      len++;
    keym[key] = Node(value);
    update(key, 0);
  }

  void update(int key, int mode) {
    Node n = keym[key];
    int f = n.freq;

    // cases node seq do not change
    if(mode && n.next == nullptr || n.next->freq > f) {
      freqm[f] = node;
      if(n.prev == nullptr || n.prev->freq < f - 1)
        freqm.erase(f - 1);
      else
        freqm[f - 1] = n.prev;
      return;
    }
    if(!mode && keym[remove].freq > 1) {
      n.next = &keym[remove];
      keym[remove].prev = &n;
      remove = key;
      return;
    }
    // case seq order change
    if(mode) {
      if(n.prev == nullptr) {
        remove = n.next; // problem occured
        n.next->prev = nullptr;
        freqm.erase(f - 1);
      } else {
        n.prev->next = n.next;
        n.next->prev = n.prev;
        if(n.prev->freq == f - 1)
          freqm[f - 1] = n.prev;
        else
          freqm.erase(f - 1);
      }
    }
    
    if(freqm[f]->next != nullptr) {
      freqm[f]->next->prev = &n;
      n.next = freqm[f]->next;
    } else {
      n.next = nullptr;
    }
    freqm[f]->next = &n;
    n.prev = *freqm[f];
    freqm[f] = &n;
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
