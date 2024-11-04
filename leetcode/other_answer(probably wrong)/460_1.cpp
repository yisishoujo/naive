#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LFUCache { // time limit exceed
private:
  unordered_map<int, int> mum;
  vector<pair<int, int>> vii;
  int cap;
  int len;
public:
  LFUCache(int capacity) {
    cap = capacity - 1;
    len = 0;
  }
    
  int get(int key) {
    if(mum.find(key) == mum.end())
      return -1;
    update(key);
    return mum[key];
  }
    
  void put(int key, int value) {
    if(mum.find(key) != mum.end()) {
      mum[key] = value;
      update(key);
      return;
    }
    if(len > cap) {
      mum.erase(vii[cap].first);
      vii[cap].first = key;
      vii[cap].second = 0;
    } else {
      vii.push_back({key, 0});
      len++;
    }
    mum[key] = value;
    update(key);
  }

  void update(int key) {
    int count;
    int i = len - 1;
    for( ; i >= 0; i--) {
      if(vii[i].first == key) {
        vii[i].second++;
        count = vii[i].second;
        break;
      }
    }
    i--;
    for( ; i >= 0; i--) {
      if(vii[i].second <= count) {
        swap(vii[i], vii[i+1]);
      } else {
        return;
      }
    }
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
