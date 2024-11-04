#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
  vector<int> di = {-1, 0, 1, 0};
  vector<int> dj = {0, -1, 0, 1};
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    bitset<36> visited;

    char w = word[0];
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(board[i][j] == w) {
          visited[i*n+j] = true;
          if(helper(board, m, n, i, j, visited, word.substr(1))) {
            return true;
          }
          visited[i*n+j] = false;
        }
      }
    }
    return false;
  }

  bool helper(vector<vector<char>>& board, int m, int n, int i, int j, bitset<36> visited, string word) {
    if(word.size() == 0)
      return true;
    for(int k = 0; k < 4; k++) {
      int ni = i+di[k];
      int nj = j+dj[k];
      if(ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni*n+nj] && board[ni][nj] == word[0]) {
        visited[ni*n+nj] = true;
        if(helper(board, m, n, ni, nj, visited, word.substr(1))) {
          return true;
        }
        visited[ni*n+nj] = false;
      }
    }
    return false;
  }
};
