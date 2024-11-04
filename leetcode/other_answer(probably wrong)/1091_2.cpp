#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution { // beats 33%
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if(n <= 0)
      return -1;
    if(grid[0][0] != 0)
      return -1;

    vector<vector<int>> vec(n, vector<int>(n, 0));
    queue<pair<int, int>> myq;
    vector<int> addi = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> addj = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    myq.push({0, 0});
    while(!myq.empty()) {
      auto a = myq.front();
      myq.pop();
      int i = a.first;
      int j = a.second;
      if(grid[i][j] == 0 && vec[i][j] == 0) {
        int len = 0;
        for(int k = 0; k < 8; k++) {
          int ii = i + addi[k];
          int jj = j + addj[k];
          if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
            if(grid[ii][jj] == 0 && vec[ii][jj] == 0) {
              myq.push({ii, jj});
            } else if(vec[ii][jj] != 0) {
              len = (len == 0? vec[ii][jj]: min(len, vec[ii][jj]));
            }
          }
        }
        vec[i][j] = len + 1;
      }
      if(i == n-1 && j == n-1) {
        return vec[n-1][n-1];
      }
    }
    return -1;  
  }
};

int main() {
  vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};

  Solution solution;
  cout << solution.shortestPathBinaryMatrix(grid) << endl;
  return 0;
}
