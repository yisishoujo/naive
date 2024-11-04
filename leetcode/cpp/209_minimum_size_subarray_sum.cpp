#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = 0, sum = 0;
    int result = n+1;
    while(r < n || sum >= target) {
      if(sum < target) {
        sum += nums[r];
        r++;
      } else {
        result = min(result, r-l);
        sum -= nums[l];
        l++;
      }
    }
    if(result == n+1)
      return 0;
    return result;
  }
};

int main() {
  vector<int> nums = {1,2,3,4,5};
  Solution solution;
  cout << solution.minSubArrayLen(15, nums) << endl;
  return 0;
}
