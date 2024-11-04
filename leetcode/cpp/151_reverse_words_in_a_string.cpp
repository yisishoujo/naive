#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// stupid spaces, if there are so many spaces, i might move space to end first
class Solution {
public:
  string reverseWords(string s) {
    s += ' ';
    reverse(s.begin(), s.end());
    s += ' '; // just like dummyhead
    auto it = s.begin();
    bool mode = false;
    auto left = it, right = it;
    while(it != s.end()) {
      if(!mode && *it != ' ') {
        mode = true;
        right = it;
      }
      if(mode && *it == ' ') {
        mode = false;
        reverse(left, it);
        left = left + distance(right, it) + 1; // can not use it - right
      }
      it++;
    }
    left--;
    s.resize(distance(s.begin(), left)); // faster than s.erase(left, s.end());
    return s;
  }
};

int main() {
  string s = "  hello world   ";
  Solution solution;
  cout << solution.reverseWords(s) << endl;
  return 0;
}
