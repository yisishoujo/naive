#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
*/

class Solution { // the best answer (other person's)
public:
  int removeElement(vector<int>& nums, int val) {
    int left = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] != val) {
        nums[left] = nums[i];
        left++;
      }
    }
    
    return left;
  }
};

int main() {
  vector<int> nums = {0,1,2,2,3,0,4,2};
  int val = 2;

  Solution solution;

  cout << solution.removeElement(nums, val) << endl;
  return 0;
}
