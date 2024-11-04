#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution { // obviously you need to do it backwards
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> vi(n, 0);

    for(int i = n - 1; i >= 0; i--) {
      int ma = 0;
      for(int j = i+1; j < n; j++) {
        if(nums[j] > nums[i] && vi[j] > ma)
          ma = vi[j];
      }
      vi[i] = ma + 1;
    }

    return *max_element(vi.begin(), vi.end());
  }
};
