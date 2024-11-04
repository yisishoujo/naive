#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int nn;
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    nn = n - 1;
    int x = 0, y = 0;
    result[x][y] = 1;
    for(int i = 2; i <= n*n; i++) {
      next(x, y);
      result[x][y] = i;
    }
    return result;
  }

  void next(int &x, int &y) {
    if(x <= y+1 && x + y < nn)
      y++;
    else if(x < y && x + y >= nn)
      x++;
    else if(x >= y && x + y > nn)
      y--;
    else if(x > y+1 && x + y <= nn)
      x--;
  }
};
