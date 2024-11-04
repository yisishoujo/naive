#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
  queue<pair<int, int>> q; // might have duplicates in q
  int m;
  int n;
  set<pair<int, int>> remains;
  int closedIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    if(m <= 2 || n <= 2)
      return 0;
    
    int count = 2;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(grid[i][j] == 0) {
          if(i == 0 || i == m-1 || j == 0 || j == n-1) {
            mywrite(grid, i, j, count);
          } else {
            remains.insert({i, j});
          }
        }
      }
    }
    
    do {
      while(!q.empty()) {
        auto a = q.front();
        mywrite(grid, a.first, a.second, count);
        q.pop();
      }
      count++;
      auto it = remains.begin();
      q.push(*it);
    } while(!remains.empty());

    return count - 3;

  }

  void mywrite(vector<vector<int>>& grid, int i, int j, int k) {
    grid[i][j] = k;
    remains.erase({i, j});
    if(i >= 1 && grid[i-1][j] == 0) q.push({i-1, j});
    if(j >= 1 && grid[i][j-1] == 0) q.push({i, j-1});
    if(i < m-1 && grid[i+1][j] == 0) q.push({i+1, j});
    if(j < n-1 && grid[i][j+1] == 0) q.push({i, j+1});
  }
};

int main() {
  vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};

  Solution solution;
  cout << solution.closedIsland(grid) << endl;
  return 0;
}
