#include <iostream>
#include <string>

using namespace std;

/*
Given a string s, return the longest palindromic substring in s.
最长的回文子串
 */

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    int maxLength = 1;
    int index = 0;
    int length = 1;

    for(int i = 0; i < n*2 - 2; i++) {
      int j = (i+1)/2;
      for(; j < n; j++) {
        if((i >= j) && s[j] == s[i - j])
          continue;
        break;
      }
      length = 2*j - i - 1;
      if(length > maxLength) {
        maxLength = length;
        index = i - j + 1;
      }
    }

    return s.substr(index, maxLength);
  }
};

int main() {
  string s = "babd";

  Solution solution;
  
  cout << solution.longestPalindrome(s) << endl;
  return 0;
}
