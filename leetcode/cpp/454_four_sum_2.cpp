#include <unordered_map>

using namespace std;

class Solution {
public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int n = nums1.size();
    unordered_map<int, int> um1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        um1[nums1[i]+nums2[j]]++;
      }
    }
    int result = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(um1.count(-nums3[i]-nums4[j]))
          result += um1[-nums3[i]-nums4[j]];
      }
    }
    return result;
  }
};

/*
class Solution { // this one is faster // probably because of the test cases
public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int n = nums1.size();
    unordered_map<int, int> um1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        um1[nums1[i]+nums2[j]]++;
      }
    }
    unordered_map<int, int> um2;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        um2[nums3[i]+nums4[j]]++;
      }
    }

    int result = 0;
    for(auto p: um1) {
      result += p.second*um2[-p.first];
    }
    return result;
  }
};
*/
