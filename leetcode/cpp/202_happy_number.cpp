

class Solution {
public:
  bool isHappy(int n) {
    unordered_map<int, bool> um;
    while(n != 1) {
      if(um.count(n))
        return false;
      um[n] = true;
      n = squareofdigits(n);
    }
    return true;
  }

  int squareofdigits(int n) {
    int sum = 0;
    while(n != 0) {
      sum += (n%10)*(n%10);
      n /= 10;
    }
    return sum;
  }
};
