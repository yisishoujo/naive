#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Foo {
public:
  int order;
  Foo() {
    order = 0;
  }

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    order = 1;
  }

  void second(function<void()> printSecond) {
    while(order != 1) {
      this_thread::sleep_for(chrono::milliseconds(1));
    }
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    order = 2;
  }

  void third(function<void()> printThird) {
    while(order != 2) {
      this_thread::sleep_for(chrono::milliseconds(1));
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
