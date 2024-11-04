#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class FixedLengthPQ {
public:
  FixedLengthPQ(size_t maxSize) : maxSize(maxSize) {}

  void push(int value) {
    if (pq.size() < maxSize) {
      pq.push(value);
    } else if (value > pq.top()) {
      pq.pop();       // Remove the smallest if the new element is larger
      pq.push(value); // Add the new element
    }
  }

  int getTop() const {
    return pq.top();
  }

private:
  size_t maxSize;
  priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
};

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    FixedLengthPQ fk = FixedLengthPQ(k);
    for(int i = 0; i < nums.size(); i++) {
      fk.push(nums[i]);
    }
    return fk.getTop();
  }
};
