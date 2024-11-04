#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution { // 一次就过了 感觉良好
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(),
         [](const auto& a, const auto& b) {
           return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
         });

    int n = people.size();
    
    vector<int> index;
    for(auto& a:people) {
      index.push_back(a[1]);
    }
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < i; j++) {
        if(index[j] >= index[i])
          index[j]++;
      }
    }
    
    vector<vector<int>> queue = vector<vector<int>>(n);
    for(int i = 0; i < n; i++) {
      queue[index[i]] = people[i];
    }
    
    return queue;
  }
};
