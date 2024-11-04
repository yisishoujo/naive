#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
  Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    vector<int> closest;
    
    for(int i = 0; i < n-2; i++) {
      int newtarget = target - nums[i];
      vector<int> newnums = vector<int>(nums.begin() + i + 1, nums.end());
      closest.push_back(nums[i] + twoSumClosest(newnums, newtarget));
    }

    sort(closest.begin(), closest.end());
    return oneClosest(closest, target);
  }

  int twoSumClosest(vector<int>& nums2, int target) {
    int n = nums2.size();
    vector<int> closest;
    
    for(int i = 0; i < n-1; i++) {
      int newtarget = target - nums2[i];
      vector<int> newnums = vector<int>(nums2.begin() + i + 1, nums2.end());
      closest.push_back(nums2[i] + oneClosest(newnums, newtarget));
    }

    sort(closest.begin(), closest.end());
    return oneClosest(closest, target);
  }

  int oneClosest(vector<int>& nums1, int target) {
    int n = nums1.size();
    int i = 0;
    for(; i < n; i++) {
      if(nums1[i] >= target)
        break;
    }
    if(i == 0)
      return nums1[i];
    if(i == n)
      return nums1[n-1];
    if(nums1[i] - target >= target - nums1[i-1])
      return nums1[i-1];
    return nums1[i];
  }
};

// 适合推广到更多的个数
// 1个的情况可以改进成二分查找，但没有太大意义，因为其余维数都是遍历查找的

int main() {
  vector<int> nums = {-1,2,1,-4};
  int target = 1;

  Solution solution;

  cout << solution.threeSumClosest(nums, target) << endl;
  return 0;
}
