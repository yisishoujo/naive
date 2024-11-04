#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> commonChars(vector<string>& words) {
    vector<int> um1(26, 0);

    for(int i = 0; i < words[0].size(); i++) {
      um1[words[0][i] - 'a']++;
    }
    
    for(int i = 1; i < words.size(); i++) {
      vector<int> um2(26, 0);
      for(int j = 0; j < words[i].size(); j++) {
        um2[words[i][j] - 'a']++;
      }
      for(int j = 0; j < 26; j++) {
        um1[j] = min(um1[j], um2[j]); // faster if remove if(um1[j] != 0)
      }
    }
    vector<string> result;
    for(int j = 0; j < 26; j++) {
      for(int i = 0; i < um1[j]; i++) {
        result.push_back(string(1,'a'+j));
      }
    }
    return result;
  }
};
