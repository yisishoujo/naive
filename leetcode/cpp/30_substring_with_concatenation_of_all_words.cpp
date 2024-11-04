#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

    For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.

Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
 */

class Solution { // struggled a lot 总是超时
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> index = vector<int>();
    int word_num = words.size();
    int word_len = words[0].size();
    int n = s.size();
    int m = word_num * word_len;

    if(n-m < 0)
      return index;
    
    map<string, int> word_map;
    
    for(auto & word: words) {
      word_map[word]++;
    }
 
    for(int i = 0; i < word_len; i++) {
      map<string, int> test_map;
      for(int j = 0; j < word_num; j++) {
        string t = s.substr(i+j*word_len, word_len);
        if(word_map.find(t) != word_map.end())
          test_map[t]++;
      } 
      if(test_map == word_map)
        index.push_back(i);

      for(int l = i+m; l <= n-word_len; l = l+word_len) {
        string t = s.substr(l, word_len);
        if(word_map.find(t) != word_map.end())
          test_map[t]++;
        t = s.substr(l-m, word_len);
        if(word_map.find(t) != word_map.end())
          test_map[t]--;
        if(test_map == word_map)
          index.push_back(l-m+word_len);
      }
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
  string s = "barfoothefoobarman";
  vector<string> words = {"foo","bar"};

  Solution solution;

  printVector(solution.findSubstring(s, words));
  return 0;
}
