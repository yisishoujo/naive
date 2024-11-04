#include <iostream>
#include <string>

using namespace std;

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
*/

class Solution { // looks ugly
public:
  string convert(string s, int numRows) {
    int n = s.size();
    if(numRows == 1) return s;

    string output = "";
    int m = 2*numRows - 2;
    int k = n/m;
    int l = n - m*k;
    for(int i = 0; i < numRows; i++) {
      for(int j = 0; j < k; j++) {
        output += s[i+m*j];
        if((i != 0) && (i != numRows - 1))
          output += s[m-i+m*j];
      }
      if(i < l)
        output += s[i+m*k];
      if((i != 0) && (i != numRows - 1) && (m - i < l))
        output += s[m-i+m*k];
    }

    return output;
  }
};

int main() {
  string s = "PAYPALISHIRING";
  int numRows = 3;

  Solution solution;

  cout << solution.convert(s, numRows) << endl;
}
