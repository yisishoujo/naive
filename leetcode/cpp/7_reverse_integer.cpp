#include <iostream>
#include <limits.h>

using namespace std;

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

class Solution {
public:
  int reverse(int x) { // x range [-2^31, 2^31 - 1] -2147483648 2147483647
    int y = 0;

    while(x) {
      int digit = x%10; // -123%10 = -3 perfectly for the first digit of y
      if (y > INT_MAX/10 || y < INT_MIN/10) { 
        return 0;
      } // x位数到了最大值才可能触发 此时abs(digit)<=2

      y = 10*y + x%10;
      x = x/10;
    }

    return y;
  }
};

// INT_MAX defined in <limits.h> or <climits>

int main() {
  int x = -123;
  cout << x%10 << endl;
  Solution solution;
  cout << solution.reverse(x) << endl;
  return 0;
}
