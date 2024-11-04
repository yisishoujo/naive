#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// there is an old version in subfolder, which is 940ms runtime
// this version not changed much however is 1ms runtime
// i guess it's because of some stupid testcase
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    if(amount == 0)
      return 0;
    
    int n = coins.size();
    if(n == 1) {
      if(amount%coins[0] != 0)
        return -1;
      return amount/coins[0];
    }
    
    sort(coins.begin(), coins.end());
    int b = coins[0]; // this value used too many times
    
    if(amount == b)
        return 1;
    int d = b;
    int r = 1;
    while(r < n && amount >= coins[r]) {
      if(amount == coins[r])
        return 1;
      d = gcd(coins[r], d);
      coins[r] -= b;
      r++;
    }
    if(amount%d != 0)
      return -1;

    int mi = (amount - 1)/(coins[r-1] + b) + 1;
    int ma = amount/b;
    for(int i = mi; i <= ma; i++) {
      if(helper(coins, 1, r-1, amount - i*b, i))
        return i;
    }
    return -1;
  }

  bool helper(vector<int>& coins, int l, int r, int amount, int m) {
    if(amount == 0)
      return true;
    if(l > r || amount < coins[l] || amount/coins[r] > m)
      return false; // here is the only reason why l is a parameter
    if(amount%coins[r] == 0)
      return true;
    if(l == r) {
      return false;
    }

    int k = amount/coins[r];
    for(; k >= 0; k--) {
      if(helper(coins, l, r-1, amount-k*coins[r], m - k)) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution solution;

  vector<int> coins = {1,2};
  solution.coinChange(coins, 3);
  return 0;
}
