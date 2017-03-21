/*
** 《编程之美》3.7队列中取最大值操作问题
*/
#include <iostream>
#include <queue>
template<typename T>
class squeue: public std::queue<T> {
 public:
  squeue(std::initializer_list<T> l) {
    for (auto i : l) push(i);
  }
  T max_value() {
    return q.front();
  }
  void push(const T v) {
    std::queue<T>::push(v);
    while (q.size() && v > q.back()) q.pop_back();
    q.push_back(v);
  }
  void pop() {
    if (std::queue<T>::front() == q.front())
      q.pop_front();
    std::queue<T>::pop();
  }
 protected:
  std::deque<T> q;
};

int main() {
  squeue<int> sq{8, 8, 2, 7};
  std::cout << sq.max_value() << std::endl;
  sq.pop(); sq.pop();
  std::cout << sq.max_value() << std::endl;
  sq.push(55);
  std::cout << sq.max_value() << std::endl;
}
