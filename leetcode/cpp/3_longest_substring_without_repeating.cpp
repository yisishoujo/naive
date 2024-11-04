#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int left = 0;
    int maxLength = 0;
    unordered_map<char, int> charMap;
    for(int i = 0; i < n; i++) {
      if(charMap.find(s[i]) == charMap.end() || charMap[s[i]] < left) {
        if(maxLength < i - left + 1) {
          maxLength = i - left + 1;
        };
      } else {
        left = charMap[s[i]] + 1;
      }
      charMap[s[i]] = i;
    }
    return maxLength;
  }
};

// Notes: unordered_map
// find == end() to check if already in (same as in problem 1)

// iterate via right side

int main() {
  Solution solution;
  string s = "pwwkew";
  cout << solution.lengthOfLongestSubstring(s) << endl;
  return 0;
}
