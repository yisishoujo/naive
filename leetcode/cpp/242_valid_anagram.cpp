#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int n = s.size();
    if(t.size() != n)
      return false;
    vector<int> um(26, 0);
    for(int i = 0; i < n; i++) {
      um[s[i]-'a']++;
      um[t[i]-'a']--;
    }
    for(int i = 0; i < 26; i++) {
      if(um[i] != 0)
        return false;
    }
    return true;
  }
};

/*
class Solution {
public:
  bool isAnagram(string s, string t) {
    int n = s.size();
    if(t.size() != n)
      return false;
    unordered_map<char, int> um;
    for(int i = 0; i < n; i++) {
      um[s[i]]++;
      um[t[i]]--;
    }
    for(int i = 0; i < 26; i++) {
      if(um['a'+i] != 0)
        return false;
    }
    return true;
  }
};
*/
