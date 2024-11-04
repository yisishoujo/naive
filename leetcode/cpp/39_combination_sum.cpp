#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    sort(candidates.begin(), candidates.end(), greater<int>());

    vector<vector<int>> result;
    vector<int> chosen;
    helper(candidates, n, 0, target, chosen, result);

    return result;
  }
  
  void helper(vector<int>& candidates, int n, int l, int target, vector<int> chosen, vector<vector<int>>& result) {
    if(l >= n || l < 0)
      return;
    int a = candidates[l];
    if(l == n - 1) {
      if(target % a != 0)
        return;
      for(int i = 0; i < target/a; i++) {
        chosen.push_back(a);
      }
      sort(chosen.begin(), chosen.end());
      result.push_back(chosen);
      return;
    }

    int b = target/a;
    for(; b >= 0; b--) {
      helper(candidates, n, l+1, target, chosen, result);
      chosen.push_back(a);
      target -= a;
    }
    
  }
};
