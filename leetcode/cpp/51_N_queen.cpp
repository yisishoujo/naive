#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<short>> resulti;
    bitset<50> bs;
    vector<short> chosen;
    helper(n, 0, chosen, bs, resulti);

    int m = resulti.size();
    vector<vector<string>> result;
    
    string s;
    for(int i = 0; i < n; i++) {
      s += '.';
    }
    for(int i = 0; i < m; i++) {
      vector<string> vs(n, s);
      for(int j = 0; j < n; j++) {
        vs[j][resulti[i][j]] = 'Q';
      }
      result.push_back(vs);
    }
    return result;
  }

  void helper(int n, int l, vector<short> chosen, bitset<50> bs, vector<vector<short>>& resulti) {
    if(l >= n || l < 0)
      return;
    for(int i = 0; i < n; i++) {
      if(!bs[i] && !bs[i+l+n] && !bs[i-l+4*n]) {
        bs[i] = bs[i+l+n] = bs[i-l+4*n] = true;
        chosen.push_back(i);
        if(l == n - 1) {
          resulti.push_back(chosen);
        } else {
          helper(n, l+1, chosen, bs, resulti);
        }
        bs[i] = bs[i+l+n] = bs[i-l+4*n] = false;
        chosen.pop_back();
      }
    }
  }
};

int main() {
  Solution solution;
  solution.solveNQueens(4);
  return 0;
}
