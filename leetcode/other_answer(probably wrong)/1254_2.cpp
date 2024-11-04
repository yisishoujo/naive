#include <vector>

using namespace std;

class Solution { // learn DFS depth first search
public:
  vector<vector<bool>> visited;
  vector<int> adderx = {0, 0, 1, -1};
  vector<int> addery = {1, -1, 0, 0};
  void explore_area(vector<vector<int>> &grid, int i, int j) {
    for (int k = 0; k < 4; k++) {
      if ((i + addery[k]) < grid.size() && (i + addery[k]) >= 0 &&
          (j + adderx[k]) < grid[0].size() && (j + adderx[k]) >= 0 &&
          grid[i + addery[k]][j + adderx[k]] == 0 &&
          !visited[i + addery[k]][j + adderx[k]]) // 没有越界并且没有访问过
      {
        visited[i + addery[k]][j + adderx[k]] = true;
        explore_area(grid, i + addery[k], j + adderx[k]);
      }
    }
    return;
  }
  int closedIsland(vector<vector<int>> &grid) {
    // Using DFS
    visited.assign(grid.size(), vector<bool>(grid[0].size(), false));
    int total_islands = 0, boundary_islands = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 0 && !visited[i][j]) {
          visited[i][j] = true;
          explore_area(grid, i, j);
          total_islands++; // 寻找total_islands的步骤很简洁
        } // 下面的boundary为什么会写的这么复杂
      }
    }
    visited.assign(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++) {
      if (grid[i][0] == 0 && !visited[i][0]) {
        visited[i][0] = true;
        explore_area(grid, i, 0);
        boundary_islands++;
      }
      if (grid[i][grid[0].size() - 1] == 0 && !visited[i][grid[0].size() - 1]) {
        visited[i][grid[0].size() - 1] = true;
        explore_area(grid, i, grid[0].size() - 1);
        boundary_islands++;
      }
    }
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[0][j] == 0 && !visited[0][j]) {
        visited[0][j] = true;
        explore_area(grid, 0, j);
        boundary_islands++;
      }
      if (grid[grid.size() - 1][j] == 0 && !visited[grid.size() - 1][j]) {
        visited[grid.size() - 1][j] = true;
        explore_area(grid, grid.size() - 1, j);
        boundary_islands++;
      }
    }
    return (total_islands - boundary_islands);
  }
};
