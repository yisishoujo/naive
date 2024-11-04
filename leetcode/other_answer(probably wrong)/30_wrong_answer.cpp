#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

    For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.

Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
 */

class Solution { // 不能处理words里面有重复的情况
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int n = s.size();
    int m = words.size();
    int k = words[0].length();
    int mk = m*k;
    vector<int> index;
    bool breaktoi = false;

    for(int i = 0; i <= n - mk; i++) {
      unordered_set<int> set;
      breaktoi = false;
      for(int j = 0; j < k; j++) {
        int l = 0;
        for(; l < m; l++) {
          if(s.substr(i+j*k, k) == words[l]) {
            if(set.find(l) == set.end()) {
              set.insert(l);
              break;
            } else {
              breaktoi = true;
              break;
            }
          } 
        }
        if(breaktoi || l == m) break;
      }
      if(set.size() == m) index.push_back(i);
    }

    return index;
  }
};

// print vector like list in python
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) { // Don't print a comma after the last element
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
  string s = "wordgoodgoodgoodbestword";
  vector<string> words = {"word","good","best","good"};

  Solution solution;

  printVector(solution.findSubstring(s, words));
  return 0;
}
