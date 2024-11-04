#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CustomCompare {
  bool operator()(pair<short, int> l, pair<short, int> r) {
    return l.second < r.second;
  }
};

class FixedLengthPQ {
public:
  FixedLengthPQ(size_t maxSize) : maxSize(maxSize) {}

  void push(pair<short, int> value) {
    if (pq.size() < maxSize) {
      pq.push(value);
    } else if (CustomCompare()(value, pq.top())) {
      pq.pop();       // Remove the smallest if the new element is larger
      pq.push(value); // Add the new element
    }
  }

  vector<short> getElements() {
    vector<short> result;
    while(!pq.empty()) {
      result.push_back(pq.top().first);
      pq.pop();
    }
    return result;
  }

private:
  size_t maxSize;
  priority_queue<pair<short, int>, vector<pair<short, int>>, CustomCompare> pq;
};

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    FixedLengthPQ fk = FixedLengthPQ(k);
    for(int i = 0; i < points.size(); i++) {
      fk.push({i, points[i][0]*points[i][0] + points[i][1]*points[i][1]});
    }
    vector<short> vs = fk.getElements();
    vector<vector<int>> result;
    for(int i = 0; i < vs.size(); i++) {
      result.push_back(points[vs[i]]);
    }
    return result;
  }
};
