class Solution {
public:
  int lengthOfLastWord(string s) {
    int i = s.size() - 1;
    int l = 0;
    while(s[i] == ' ') {
      i--;
    }
    while(i >= 0  && s[i] != ' ') {
      i--;
      l++;
    }
    return l;
  }
};
