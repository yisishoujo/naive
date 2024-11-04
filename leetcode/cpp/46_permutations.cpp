#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    recur(nums, 0, n-1, result);
    return result;
  }

  void recur(vector<int>& nums, int l, int r, vector<vector<int>>& result) {
    if(l == r) {
      result.push_back(nums);
      return;
    }
    for(int i = l; i <= r; i++) {
      swap(nums[l], nums[i]);
      recur(nums, l+1, r, result);
      swap(nums[l], nums[i]);
    }
  }
};

int main() {
  vector<int> nums = {1,2,3};

  Solution solution;
  solution.permute(nums);
  return 0;
}
