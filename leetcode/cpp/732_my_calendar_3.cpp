#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class MyCalendarThree { //very uneffective make num_events sorted/linked might help
public:
  MyCalendarThree() {
    num_events[0] = 0;
  }
    
  int book(int startTime, int endTime) {
    books.push_back({startTime, endTime});
    updateNum(startTime, endTime);
    return maxNum();
  }

  void updateNum(int startTime, int endTime) {
    int start = 0;
    int end = 0;
    bool no_start = (num_events.find(startTime) == num_events.end());
    bool no_end = (num_events.find(endTime) == num_events.end());
    for(auto& pair: num_events) {
      if(no_start) {
        if(pair.first < startTime && pair.first > start)
          start = pair.first;
      }
      if(no_end) {
        if(pair.first < endTime && pair.first > end)
          end = pair.first;
      }

      if(pair.first >= startTime && pair.first < endTime)
        pair.second++;
    }

    if(no_start) {
      num_events[startTime] = num_events[start] + 1;
    }

    if(no_end) {
      if(end < startTime) {
        num_events[endTime] = num_events[end];
      } else {
        num_events[endTime] = num_events[end] - 1;
      }
    }
  }

  int maxNum() {
    auto max_value =  max_element(num_events.begin(), num_events.end(), 
                       [](const pair<int, int>& a, const pair<int, int>& b) {
                         return a.second < b.second;
                       });
    cout << max_value->second << endl; // output for test in main
    return max_value->second;
  }

private:
  vector<pair<int, int>> books;
  map<int, int> num_events;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */

int main() {
  MyCalendarThree myCalendarThree;
  myCalendarThree.book(10, 20); // return 1
  myCalendarThree.book(50, 60); // return 1
  myCalendarThree.book(10, 40); // return 2
  myCalendarThree.book(5, 15); // return 3
  myCalendarThree.book(5, 10); // return 3
  myCalendarThree.book(25, 55); // return 3

  return 0;
}
