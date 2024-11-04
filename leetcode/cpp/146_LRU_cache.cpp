#include <iostream>
#include <unordered_map>

using namespace std;

// Least Recently Used (LRU) cache

class LRUCache { // memory beats 96%, i guess it's only because use of short
public:
  unordered_map<short, pair<int, pair<short, short>>> mum;
  short head;
  short tail;
  int cap;
  int len;
  LRUCache(int capacity) {
    cap = capacity;
    len = 0;
  }
    
  int get(short key) {
    if(mum.find(key) != mum.end()) {
      auto [val, sec] = mum[key];
      auto [pkey, nkey] = sec;
      if(key == tail)
        return val;
      
      if(key == head) {
        head = nkey;
      } else {
        mum[pkey].second.second = nkey;
        mum[nkey].second.first = pkey;
      }
      
      mum[key].second.first = tail;
      mum[tail].second.second = key;
      tail = key;
      
      return val;
    }
    return -1;
  }
    
  void put(short key, int value) {
    if(len == 0) {
      head = key;
      tail = key;
      mum[key] = {value, {key, key}};
      len++;
      return;
    }
    
    if(mum.find(key) != mum.end()) {
      mum[key].first = value;
      get(key);
      return;
    }

    if (len < cap) {
      len++;
    } else {
      short temp = mum[head].second.second;
      mum.erase(head);
      head = temp;
    }
    if(len == 1)
      head = key;
    mum[key] = {value, {tail, key}};
    if(len > 1)
      mum[tail].second.second = key;
    tail = key;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache obj(1);
  obj.put(2,1);
  obj.get(2);
  obj.put(3,2);
  cout << obj.get(2) << endl;
  return 0;
}
