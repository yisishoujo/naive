#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    return helper(0, nums.size()-1, nums);
  }

  int helper(int l, int r, vector<int>& nums) {
    if(l >= r)
      return l;
    if(l == r-1) {
      if(nums[l] > nums[r])
        return l;
      return r;
    }

    int m = (l+r)/2;
    if(nums[m] < nums[m-1]) {
      return helper(l, m, nums);
    }
    if(nums[m] < nums[m+1]) {
      return helper(m+1, r, nums);
    }
    return m;
  }
};
