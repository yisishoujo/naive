#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// time limit exceed on many different test cases
// then modified to this; still 900ms runtime
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    if(amount == 0)
      return 0;
    
    int n = coins.size();
    sort(coins.begin(), coins.end());
    
    int mi = 0;
    int d = coins[0];
    while(mi < n && amount >= coins[mi]) {
      if(amount == coins[mi])
        return 1;
      d = gcd(coins[mi], d);
      if(mi > 0)
        coins[mi] -= coins[0];
      mi++;
    }
    if(mi == 0 || amount%d != 0)
      return -1;
    mi = (amount-1)/(coins[mi-1]+coins[0]) + 1;

    int ma = amount/coins[0];
    for(int i = mi; i <= ma; i++) {
      if(helper(coins, n, 1, amount-i*coins[0], i))
        return i;
    }
    return -1;
  }

  bool helper(vector<int>& coins, int n, int l, int amount, int m) {
    // true if can be represented by less than m coins
    if(amount == 0)
      return true;
    if(l >= n || amount < coins[l])
      return false;
    if(l == n-1) {
      if(amount%coins[l] == 0 && amount/coins[l] <= m)
        return true;
      return false;
    }

    int k = min(m, amount/coins[l]);
    for(int i = 0; i <= k; i++) {
      if(helper(coins, n, l+1, amount-i*coins[l], m - i)) {
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
