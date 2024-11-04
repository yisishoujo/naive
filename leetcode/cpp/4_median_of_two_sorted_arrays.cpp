#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

class Solution { // beats 95%
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int min1 = 0;
    int min2 = 0;
    int max1 = nums1.size();
    int max2 = nums2.size();

    if(max2 < max1)
      return findMedianSortedArrays(nums2, nums1);

    if(max2 - max1 >= 4) {
      int k = (max2 - max1)/2 - 1;
      min2 = k;
      max2 = max2 - k;
    }

    while((max1-min1) > 2 && (max2-min2) > 2) { // 2稍微放大点也许更快
      int med1 = nums1[(max1 + min1 - 1)/2] + nums1[(max1 + min1)/2];
      int med2 = nums2[(max2 + min2 - 1)/2] + nums2[(max2 + min2)/2];
      if(med1 == med2) return static_cast<double>(med1) / 2;
    
      int k = min((max1-min1-1)/2, (max2-min2-1)/2);
    
      if(med1 > med2) {
        max1 = max1 - k;
        min2 = min2 + k;
      } else {
        min1 = min1 + k;
        max2 = max2 - k;
      }
    }

    vector<int> final; // 最多7个元素
    final.insert(final.end(), nums1.begin() + min1, nums1.begin() + max1);
    final.insert(final.end(), nums2.begin() + min2, nums2.begin() + max2);
    sort(final.begin(), final.end());

    int len = final.size();
    return static_cast<double>(final[(len-1)/2] + final[len/2])/2;
  }
};

int main() {
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};

  Solution solution;

  cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
