#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <chrono> // For time calculations

using namespace std;

class Solution { // 成绩特别集中在最前面46%
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0)
      return 0;

    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += nums[i];
    }
    
    if(sum < target || sum%2 != target%2)
      return 0;
    target = (target + sum)/2;

    unordered_map<int, int> umap; // 参考别人的做法，可以改成数组（可能适合某些特别的数据）
    umap[0]++;
    umap[nums[0]]++;
    for(int i = 1; i < n; i++) {
      unordered_map<int, int> umap_old = umap;
      for(const auto& pair : umap_old) {
        umap[pair.first + nums[i]] += umap_old[pair.first];
      }
    }

    return umap[target];
  }
};

/*
class Solution { // 别人post的solution leetcode通不过，不允许变量数组
public:
  int findTargetSumWays(vector<int>& nums, int s) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
  }   

  int subsetSum(vector<int>& nums, int s) {
    int dp[s + 1] = { 0 };
    dp[0] = 1;
    for (int n : nums)
            for (int i = s; i >= n; i--)
              dp[i] += dp[i - n];
    return dp[s];
  }
  };
  */

/*

// other person's answer runtime is larger than mine
class Solution {
public:
  map<pair<int,int>, int> memo;
  int recursive(vector<int>&a, int index, int target){
    if(index==0){
      if(target==0) return 1;
      return 0;
    }
    pair<int,int> p= make_pair(index,target);
    if(memo.count(p)) return memo[p];
    return memo[p]= recursive(a,index-1,target-a[index-1]) + recursive(a,index-1,target+a[index-1]);
  }
  int findTargetSumWays(vector<int>& a, int target) {
    return recursive(a ,a.size(),target);
  }
  };
  */

/*

// 结果似乎是正确的 submit不过 Time Limit Exceeded / Memory Limit Exceeded
// 结果特别大的时候容易出现
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0)
      return 0;
    sort(nums.begin(), nums.end());
    int sum = 0;
    vector<int> sums;
    for(int i = 0; i < n; i++) {
      sum += nums[i];
      sums.push_back(sum);
    }
    if(sum < target || sum%2 != target%2)
      return 0;
    target = (target + sum)/2;

    int index = n - 1;
    while(target > sums[index]) {
      index--;
      if(index < 0)
        return 0;
    } 

    return findsort(nums, sums, target, index);
  }

  int findsort(vector<int>& nums, vector<int> sums, int target, int index) {
    if(target > sums[index] || target < 0)
      return 0;
    if(index == 0) {
      return (target == nums[0]? 1:0) + (target == 0? 1:0);
    }
    if(target < nums[index])
      return findsort(nums, sums, target, index-1);
    return findsort(nums, sums, target - nums[index], index-1) + findsort(nums, sums, target, index-1);
  }
};
 */

int main() {
  //vector<int> nums = {5,19,48,39,14,5,39,32,5,46,11,30,1,20,36,15,21,6,15,2};
  //int target = 39;
  //vector<int> nums = {22,36,7,44,38,32,16,32,1,16,25,45,49,45,27,9,41,31,10,15};
  //int target = 1;
  //vector<int> nums = {1,1,1,1,1};
  //int target = 3;
  vector<int> nums = {9,7,0,3,9,8,6,5,7,6};
  int target = 2;
  
  Solution solution;
  auto start = chrono::high_resolution_clock::now();
  cout << solution.findTargetSumWays(nums, target) << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, std::milli> duration = end - start;
  cout << "Runtime: " << duration.count() << " ms" << endl;
  return 0;
}
