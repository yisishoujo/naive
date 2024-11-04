

class Solution {
public:
  int climbStairs(int n) {
    int even = 1;
    int odd = 1;
    for(int i = 0; i < n/2; i++) {
      even += odd;
      odd += even;
    }
    if(n%2)
      return odd;
    return even;
  }
};
// n=45 is at the edge of overflow
