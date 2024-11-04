#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution { // Time Limit Exceeded 不要做string操作，改数字
public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead;
    for(auto& d: deadends) {
      dead.insert(d);
    }
    
    unordered_map<string, int> reached;
    queue<string> myq, myn;
    myq.push("0000");
    int count = 1; // count没有实现放弃
    while(!myq.empty()) {
      string a = myq.front();
      myq.pop();
      if(a == target)
        return count;
      if(dead.find(a) == dead.end()) {
        reached[a] = count;
        for(auto & s: getDigitNeighbors(a)) {
          if(reached[s] == 0 && dead.find(s) == dead.end()) {
            myn.push(s);
          }
        }
      }
    }
    return -1;
    
  }
  vector<string> getDigitNeighbors(const string& input) {
    // Map each digit to its neighbors
    unordered_map<char, vector<char>> digit_neighbors = {
      {'0', {'9', '1'}},
      {'1', {'0', '2'}},
      {'2', {'1', '3'}},
      {'3', {'2', '4'}},
      {'4', {'3', '5'}},
      {'5', {'4', '6'}},
      {'6', {'5', '7'}},
      {'7', {'6', '8'}},
      {'8', {'7', '9'}},
      {'9', {'8', '0'}}
    };
    
    vector<string> neighbors;
    for (size_t i = 0; i < input.size(); ++i) {
      char original = input[i];
      for (char neighbor : digit_neighbors[original]) {
        string modified = input;
        modified[i] = neighbor;
        neighbors.push_back(modified);
      }
    }

    return neighbors;
  }
};

int main() {
  vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
  string target = "8888";

  Solution solution;
  cout << solution.openLock(deadends, target) << endl;
  return 0;
}
