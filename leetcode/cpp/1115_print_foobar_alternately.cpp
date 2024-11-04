#include <iostream>
#include <threads>
#include <condition_variable>
#include <mutex>

using namespace std;

class FooBar {
private:
  int n;
  bool newcycle;
  condition_variable cv;
  mutex mtx;

public:
  FooBar(int n) {
    this->n = n;
    newcycle = true;
  }

  void foo(function<void()> printFoo) {
        
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> lock(mtx);
      cv.wait(lock, [this] { return newcycle;});
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      newcycle = false;
      cv.notify_all();
    }
  }

  void bar(function<void()> printBar) {
        
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> lock(mtx);
      cv.wait(lock, [this] { return !newcycle;});
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      newcycle = true;
      cv.notify_all();
    }
  }
};
