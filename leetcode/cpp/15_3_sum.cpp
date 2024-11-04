#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        return result;
      }
      // if (nums[i] == nums[i + 1])，将会漏掉-1,-1,2 这种情况
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (right > left) {
        // 去重复逻辑
        if (nums[i] + nums[left] + nums[right] > 0) right--;
        else if (nums[i] + nums[left] + nums[right] < 0) left++;
        else {
          result.push_back(vector<int>{nums[i], nums[left], nums[right]});
          // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
          while (right > left && nums[right] == nums[right - 1]) right--;
          while (right > left && nums[left] == nums[left + 1]) left++;
          // 找到答案时，双指针同时收缩
          right--;
          left++;
        }
      }
    }
    return result;
  }
};


/*
struct VectorHash {
  size_t operator()(const vector<int>& vec) const {
    size_t hash = 0;
    for (int num : vec) {
      hash ^= std::hash<int>()(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    }
    return hash;
  }
};

struct VectorEqual {
  bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
    return lhs == rhs; // Use the default equality operator for vectors
  }
};

class Solution { // still time limit exceeded // on all zero
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, int> um;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
      um[nums[i]] = i;
    }

    unordered_set<vector<int>, VectorHash, VectorEqual> us;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        if(!um.count(-nums[i]-nums[j]))
          continue;
        vector<int> arr = {um[nums[i]], um[nums[j]], um[-nums[i]-nums[j]]};
        if(um[nums[arr[2]]] == i || um[nums[arr[2]]] == j)
          continue;
        sort(arr.begin(), arr.end());
        us.insert(arr);
      }
    }

    vector<vector<int>> result;
    for(auto v: us) {
      result.push_back({nums[v[0]], nums[v[1]], nums[v[2]]});
    }
    return result;
    
  }
};
*/

/*
class Solution { // time limit exceeded // stupid testcase
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<vector<int>> result;
    for(int i = 0; i < n; i++) {
      int left = i + 1;
      int right = n - 1;
      while(right > left) {
        if(nums[i]+nums[left]+nums[right] > 0) {
          right--;
        } else if(nums[i]+nums[left]+nums[right] < 0) {
          left++;
        } else {
          helper(result, nums[i], nums[left], nums[right]);
          left++;
        }
      }
    }

    return result;
  }

  void helper(vector<vector<int>>& result, int i, int j, int k) {
    for(auto v: result) {
      if(v[0] == i && v[1] == j && v[2] == k)
        return;
    }
    result.push_back({i,j,k});
  }
};
*/
