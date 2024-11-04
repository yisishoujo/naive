#include <iostream>
#include <vector>

using namespace std;

class Solution { // beats 84%
public:
  vector<vector<bool>> visited;
  vector<int> adderx = {0, 0, 1, -1};
  vector<int> addery = {1, -1, 0, 0};
  int m;
  int n;
  void explore_area(vector<vector<int>> &grid, int i, int j) {
    for (int k = 0; k < 4; k++) {
      if ((i + addery[k]) < m && (i + addery[k]) >= 0 &&
          (j + adderx[k]) < n && (j + adderx[k]) >= 0 &&
          grid[i + addery[k]][j + adderx[k]] == 0 &&
          !visited[i + addery[k]][j + adderx[k]])
      {
        visited[i + addery[k]][j + adderx[k]] = true;
        explore_area(grid, i + addery[k], j + adderx[k]);
      }
    }
    return;
  }
  pair<int, int> nextb(pair<int, int> b) {
    if(b.first == 0) {
      if(b.second == n - 1)
        return {1, n - 1};
      return {0, b.second + 1};
    }
    if(b.second == n - 1) {
      if(b.first == m - 1)
        return {m - 1, n - 2};
      return {b.first + 1, n - 1};
    }
    if(b.first == m - 1) {
      if(b.second == 0)
        return {m - 2, 0};
      return {m - 1, b.second - 1};
    }
    if(b.second == 0) {
      return {b.first - 1, 0};
    }
    return {0, 0};
  }
  int closedIsland(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();
    if(m <= 2 || n <= 2) // needed otherwise runtime error when submit
      return 0;
    
    visited.assign(m, vector<bool>(n, false));
    int closed_islands = 0;

    pair<int, int> b = {0,0};
    do {
      if(grid[b.first][b.second] == 0 && !visited[b.first][b.second]) {
        visited[b.first][b.second] = true;
        explore_area(grid, b.first, b.second);
      }
      b = nextb(b);
    } while(b.first || b.second); // can not use b != {0, 0}
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0 && !visited[i][j]) {
          visited[i][j] = true;
          explore_area(grid, i, j);
          closed_islands++;
        }
      }
    }
    return closed_islands;
  }
};

int main() {
  vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};

  Solution solution;
  cout << solution.closedIsland(grid) << endl;
  return 0;
}
