//
// Created by sun on 16-9-26.
//

#include <mutex>
#include <condition_variable>
#include <thread>
#include <zconf.h>
#include "utils.h"
using namespace std;
template<typename T>
class BlockingQueue
{
 public:
  BlockingQueue (size_t capacity) : _mutex (), _condvar (), _queue(), _capacity(capacity)
  {
  }

  void Put (const T& task)
  {
    {
      std::unique_lock<std::mutex> lock (_mutex);
      _condvar.wait (lock, [this]{return _queue.size()<_capacity;});
      _queue.push_back (task);
    }
    _condvar.notify_all ();
  }

  T Take ()
  {
    std::unique_lock<std::mutex> lock (_mutex);
    _condvar.wait (lock, [this]{return !_queue.empty ();});
    assert (!_queue.empty ());
    T front (_queue.front ());
    _queue.pop_front ();
    _condvar.notify_all();

    return front;
  }

  size_t Size() const
  {
    std::lock_guard<std::mutex> lock (_mutex);
    return _queue.size();
  }
 private:
  BlockingQueue (const BlockingQueue& rhs);
  BlockingQueue& operator = (const BlockingQueue& rhs);
 private:
  mutable std::mutex _mutex;
  std::condition_variable _condvar;
  size_t _capacity;
  std::list<T> _queue;
};

template<typename T>
class queue_with_max {
  list<T> q;
  list<T> max_q;
 public:
  void push_back(const T &t) {
    q.push_back(t);
    while (!max_q.empty() && t > max_q.back()) {
      max_q.pop_back();
    }
    max_q.push_back(t);
  }
  T &front() {
    return q.front();
  }
  T max_ele() {
    assert (max_q.front()==*max_element(q.begin(),q.end()));
    return max_q.front();
  }
  T pop_front() {
    T &t = q.front();
    q.pop_front();
    if (t == max_q.front())
      max_q.pop_front();
    return t;
  }
};

void test_queue_with_max() {
  srand(time(0));
  queue_with_max<int> q;
  vector<int> A;
  string s;
  for (int i = 0; i < 1000; i++) {
    A.push_back(rand()%100);
  }
  cout<<A<<endl;
  for (int i = 0; i < A.size(); i++) {
    q.push_back(A[i]);
    if(i>5)
      q.pop_front();
    cout<<q.max_ele()<<" ";
  }
}
int main(){
  srand(time(0));
  BlockingQueue<int> q(1);
  volatile bool running =true;
  auto th1=thread([&]{
    for(int i=0;i<5;i++) {

      q.Put(i);
      cout<<"put "<<q.Size()<<" "<< i<<endl;

    }
    running=false;
  });
  auto th2=thread([&]{
    while(running){
      size_t s=q.Size();
      cout<<"take "<<s<<" "<<q.Size()<<" "<<q.Take()<<endl;
      sleep(1);
    }

  });
  th1.join();
  th2.join();
}
