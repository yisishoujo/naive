#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution { // feels good on this one
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int result = 0;
    int n = isConnected.size();
    set<int> remain;
    for(int i = 0; i < n; i++) {
      remain.insert(i);
    }

    while(!remain.empty()) {
      set<int> current;
      auto a = remain.begin();
      current.insert(*a);
      remain.erase(*a);

      bool changed;
      do {
        changed = false;
        for(auto r = remain.begin(); r != remain.end(); ++r) {
          for(auto c = current.begin(); c != current.end(); ++c) {
            if(isConnected[*r][*c]) {
              current.insert(*r);
              remain.erase(*r);
              changed = true;
              break;
            }
          }
        }
      } while(changed);

      result++;
    }

    return result;
  }
};

int main() { // test usage of set
    std::set<int> s = {5, 10, 3, 8};

    // Loop through the set
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";  // Dereferencing the iterator to get the value
    }
    std::cout << std::endl;

    return 0;
}
