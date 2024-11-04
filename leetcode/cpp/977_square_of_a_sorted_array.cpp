#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);
    
    int l =0 , r = n -1;
    for(int i = n - 1; i >= 0; i--) {
      if(nums[l] + nums[r] <= 0) {
        result[i] = nums[l]*nums[l];
        l++;
      } else {
        result[i] = nums[r]*nums[r];
        r--;
      }
    }
    return result;
  }
};
