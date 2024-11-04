#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    int i = 0, j = 0;
    while(i <= n - m && j < m) {
      if(haystack[i+j] != needle[j]) {
        j = 0;
        i++;
      } else {
        j++;
      }
    }
    if(j == m)
      return i;
    return -1;
  }
};
