#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, -1, 0, 1};
  int m;
  int n;
  int numIslands(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    int count = 0;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(!visited[i][j] && grid[i][j] == '1') {
          visit(i, j, grid, visited);
          count++;
        }
      }
    }
    return count;
  }

  void visit(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    for(int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[x][y] == '1') {
        visit(nx, ny, grid, visited);
      }
    }
  }
};
