#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
*/

/*

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        } // 和下面做法是一样的 不需要dict中转 更简洁
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        } // 没有排序，下面按照各分组个数大小排序了
        return ans;
    }
};

*/

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> groupSort;
    for (const auto& str : strs) {
      string x = str;
      sort(x.begin(), x.end());
      groupSort[x].push_back(str);
    } // 单词sorted作为key value是向量 往向量存入单词

    // 把groupedByValue复制了一份，改了下类型（的名字，其实是一样的）
    vector<pair<string, vector<string>>> sortedGroups(groupSort.begin(), groupSort.end());

    // Sort begin到end by size
    sort(sortedGroups.begin(), sortedGroups.end(), 
              [](const auto& a, const auto& b) {
                  return a.second.size() > b.second.size();  // Descending order
              });

    // Extract only the `vector<string>` part
    vector<vector<string>> result;
    for (const auto& group : sortedGroups) {
        result.push_back(group.second);
    }

    return result;
  }
};

void printVectorOfVectors(const vector<vector<string>>& vec) {
    for (const auto& innerVec : vec) {
        for (const auto& str : innerVec) {
            cout << str << " ";  // Output each string in the inner vector
        }
        cout << endl;  // Newline after each inner vector
    }
}

int main() {
  vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

  Solution solution;
  
  printVectorOfVectors(solution.groupAnagrams(strs));

  return 0;
}
