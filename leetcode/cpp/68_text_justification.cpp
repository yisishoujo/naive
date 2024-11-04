#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution { // 87% uses 0ms of runtime
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<int> len;
    int n = words.size();
    for(int i = 0; i < n; i++)
      len.push_back(words[i].size());
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int num = 0;
    vector<string> result;
    do {
      while(right != n && sum + len[right] <= maxWidth) {
        sum += len[right] + 1;
        num++;
        right++;
      }
      
      string s;
      int t = maxWidth - sum + 1;
      int r = 0;
      
      if(right == n) {
        for(int i = left; i < n - 1; i++) {
          s += words[i];
          s += ' ';
        }
        s += words[n-1];
        for(int j = 0; j < t; j++) {
          s += ' ';
        }
        result.push_back(s);
        return result;
      }

      if(num >= 2) {
        r = t % (num - 1);
        t /= num - 1;
        t++;
        for(int i = left; i < right - 1; i++) {
          s += words[i];
          if(r > 0) {
            s += ' ';
            r--;
          }
          for(int j = 0; j < t; j++) {
            s += ' ';
          }
        }
        s += words[right - 1];
      } else {
        s += words[left];
        for(int i = 0; i < t; i++) {
          s += ' ';
        }
      }
      result.push_back(s);
      left = right;
      sum = 0;
      num = 0;
    } while(left != n);

    return result;
  }
};

int main() {
  Solution solution;

  vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;

  solution.fullJustify(words, maxWidth);
  return 0;
}
