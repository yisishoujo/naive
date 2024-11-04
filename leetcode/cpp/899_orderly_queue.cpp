#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
  string orderlyQueue(string s, int k) {
    if(k > 1) {
      string ss = s;
      sort(ss.begin(), ss.end());
      return ss;
    }
    if(k == 1) {
      int n = s.size();
      string ss = s + s;
      for(int i = 0; i < n; i++) {
        map<string, vector<int>> count;
        for(int j = 0; j < n; j++) {
          count[ss.substr(j, i)].push_back(j);
        }
        if(count.begin()->second.size() == 1) {
          string result = ss.substr(count.begin()->second[0], n);
          return result;
        }
      }
    }
    return s;
  }
};
