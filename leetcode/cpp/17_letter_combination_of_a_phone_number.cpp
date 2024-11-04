#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
  //vector<vector<string>> n2l = {{"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}};
  vector<string> n2l = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> letterCombinations(string digits) {
    vector<int> nums;
    for(auto it = digits.begin(); it != digits.end(); it++) {
      nums.push_back(*it - 50);
      // int i;
      // stringstream s;
      // s << *it;
      // s >> i;
      // nums.push_back(i - 2);
    }
    vector<string> result;
    helper(nums, 0, nums.size() - 1, "", result);
    return result;
  }

  void helper(const vector<int>& nums, int l, int r, string str, vector<string>& result) {
    if(l > r)
      return;
    int m = nums[l];
    if(m < 0 || m > 7)
      return;
    int n = n2l[m].size();
    for(int i = 0; i < n; i++) {
      string s = str + n2l[m][i];
      if(l == r) {
        result.push_back(s);
      } else {
        helper(nums, l+1, r, s, result);
      }
    }
  }
};

int main() {
  string digits = "23";
  Solution solution;
  solution.letterCombinations(digits);
  return 0;
}
