#include <vector>

class MyCalendar {
public:
  vector<pair<int, int>> books;
  MyCalendar() {
        
  }
    
  bool book(int start, int end) {
    for(const auto& b: books) {
      if(start <= b.first) {
        if(b.first < end)
          return false;
      } else if(start < b.second) {
        return false;
      }
    }
    books.push_back({start, end});
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
