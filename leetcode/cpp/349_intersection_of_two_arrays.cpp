#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1;
    for(int i = 0; i < nums1.size(); i++) {
      set1.insert(nums1[i]);
    }
    set<int> set2;
    for(int i = 0; i < nums2.size(); i++) {
      set2.insert(nums2[i]);
    }

    vector<int> result;
    set_intersection(set1.begin(), set1.end(),
                     set2.begin(), set2.end(),
                     back_inserter(result));
    return result;
  }
};

int main() {
  vector<int> nums1 = {4,9,5};
  vector<int> nums2 = {9,4,9,8,4};

  Solution solution;
  solution.intersection(nums1, nums2);

  return 0;
}
