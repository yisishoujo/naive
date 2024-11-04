#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    vector<int> stack;
    int n = pushed.size();
    int j = 0;
    for(int i = 0; i < n; i++) {
      stack.push_back(pushed[i]);
      while(j < n && !stack.empty() && stack.back() == popped[j]) {
        stack.pop_back();
        j++;
      }
    }
    return stack.size() == 0;
  }
};

/*
class Solution { // very uneffective answer; use stack
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    map<int, int> normalize;
    int n = pushed.size();
    for(int i = 0; i < n; i++) {
      normalize[pushed[i]] = i;
    }
    vector<int> newpop;
    for(auto& a:popped) {
      newpop.push_back(normalize[a]);
    }
    if(newpop.size() < n)
      return false;
    if(n <= 2)
      return true;

    map<int, int> count;
    for(int i = 0; i < n - 1; i++) {
      count[newpop[i]]++;
      if(newpop[i] > newpop[i+1] + 1) {
        int j = newpop[i] - 1;
        while(j > newpop[i+1]) {
          if(count[j] == 0)
            return false;
          j--;
        }
      }
    }
    return true;
  }
};
*/
int main() {
  vector<int> pushed = {1,2,3,4,5};
  vector<int> popped = {4,5,3,2,1};

  Solution solution;
  cout << solution.validateStackSequences(pushed, popped) << endl;
  return 0;
}
