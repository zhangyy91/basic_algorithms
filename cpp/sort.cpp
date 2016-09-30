//
// Created by sun on 16-8-26.
//

#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <functional>
#include <string.h>
using namespace std;
template<typename T>
ostream &operator<<(ostream &out, const vector<T> &vv) {
  out << "[";
  if (vv.size() > 0)
    out << vv[0];
  for (int i = 1; i < vv.size(); i++) {
    out << "," << vv[i];
  }
  out << "]";
  return out;
}

struct Int {
  static size_t cmp_count;
  int value;
  Int(int i = 0) : value(i) {}
  friend ostream &operator<<(ostream &os, const Int &anInt) {
    os << anInt.value;
    return os;
  }
  bool operator<(const Int &rhs) const {
    ++cmp_count;
    return value < rhs.value;
  }
  bool operator==(const Int &rhs) const {
    ++cmp_count;
    return value == rhs.value;
  }
  bool operator!=(const Int &rhs) const {
    return !(rhs == *this);
  }
  bool operator>(const Int &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const Int &rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const Int &rhs) const {
    return !(*this < rhs);
  }

};
size_t Int::cmp_count = 0;
template<typename T>
void qsort1(T &A, int begin, int end) {
  if (end - begin <= 1)return;
  int x = begin, i = begin, j = end - 1;
  while (i < j) {
    while (i < j && A[j] >= A[x])--j;
    while (i < j && A[i] <= A[x])++i;
    if (i < j)
      swap(A[i], A[j]);
  }
  swap(A[x], A[i]);
  qsort1(A, begin, i);
  qsort1(A, i + 1, end);
}
template<typename T>
void bubblesort(T &A, int begin, int end) {
  if (end - begin <= 1)return;
  int x = begin, i = begin, j = end - 1;
  bool flag = true;
  for (int i = 0; i < end && flag; i++) {
    flag = false;
    for (int j = i + 1; j < end; j++) {
      if (A[i] > A[j]) {
        swap(A[i], A[j]);
        flag = true;
      }
    }
  }
}
template<typename T>
void insertsort(T &A) {
  for (int i = 0; i < A.size(); i++) {
    for (int j = i; j > 0; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j - 1], A[j]);
      } else break;
    }
  }
}
template<typename T>
void choosesort(T &A) {
  for (int i = 0; i < A.size(); i++) {
    int m = i;
    for (int j = i+1; j < A.size(); j++) {
      if (A[j] < A[m]) m = j;
    }
    swap(A[i],A[m]);
  }
}
template<typename T>
void mergesort(T &A) {
  T B = A;
  T *pA = &A;
  T *pB = &B;
  bool isB = true;
  for (int gap = 1; gap < A.size() ; gap *= 2) {
    for (int i = 0, j = gap; j < A.size(); i += 2 * gap, j += 2 * gap) {
      for (int l = i, r = j, k = i; k < j + gap && k < A.size();) {
        if (l == j)(*pB)[k++] = (*pA)[r++];
        else if (r == j + gap || (*pA)[l] < (*pA)[r])(*pB)[k++] = (*pA)[l++];
        else
          (*pB)[k++] = (*pA)[r++];
      }
    }
    swap(pA, pB);
    isB = !isB;
  }
  if (isB)A = B;
}
template<typename T>
void adjustDown(T &A, int id, int end) {
  while (id < end) {
    int left = (id * 2) + 1;
    int right = (id * 2) + 2;
    if (left >= end)return;
    int big_id = left;
    if (right < end && A[right] > A[left])
      big_id = right;
    if (A[big_id] > A[id]) {
      swap(A[big_id], A[id]);
      id = big_id;
    } else return;
  }
}
template<typename T>
void heapsort(T &A, int begin, int end) {
  if (end - begin <= 1)return;
  int x = begin, i = begin, j = end - 1;
  int n = end - begin;
  for (int i = n / 2; i >= 0; --i) {
    adjustDown(A, i, end);
  }
  while (--end > 0) {
    swap(A[0], A[end]);
    adjustDown(A, 0, end);
  }

}
template<typename T>
void qsort3(T &A, int begin, int end) {
  if (end - begin <= 1)return;
  int x = end - 1, i = begin, j = end - 1;
  while (i < j) {
    while (i < j && A[i] <= A[x])i++;
    while (i < j && A[j] >= A[x])j--;
    if (i < j)
      swap(A[i], A[j]);
  }
  swap(A[x], A[i]);
  qsort3(A, begin, i);
  qsort3(A, i + 1, end);
}

int cmp(const void *a, const void *b) {
  return *(int *) a - *(int *) b;
}
int main() {

  int T;
  srand(time(0));
  cin >> T;
  int index = 0;

  Int a, b;
  bool c = a > b;
  while (T-- > 0) {

    index++;
    cout<<index<<endl;
    vector<Int> A;
    vector<tuple<string, clock_t, size_t>> checkpoint;
    for (int i = 0; i < 1000; i++) {
      A.push_back(rand());
    }
    auto B = A;
    auto C = B;
    auto D = C;
    auto E = D, F = A, G = A, H = A,chooseA=A;

    checkpoint.push_back(make_tuple("init", clock(), Int::cmp_count));
    qsort3(A, 0, A.size());
    checkpoint.push_back(make_tuple("qsort3", clock(), Int::cmp_count));
    qsort1(F, 0, A.size());
    checkpoint.push_back(make_tuple("qsort1", clock(), Int::cmp_count));
//    cout << A << endl;
//    qsort2(B);
    qsort(B.data(), B.size(), sizeof(int), cmp);

    checkpoint.push_back(make_tuple("std qsort", clock(), Int::cmp_count));
    sort(C.begin(), C.end());
    checkpoint.push_back(make_tuple("std sort", clock(), Int::cmp_count));
    bubblesort(D, 0, D.size());
    checkpoint.push_back(make_tuple("bubblesort", clock(), Int::cmp_count));
    heapsort(E, 0, E.size());
    checkpoint.push_back(make_tuple("heapsort", clock(), Int::cmp_count));

    insertsort(G);
    checkpoint.push_back(make_tuple("insertsort", clock(), Int::cmp_count));
    choosesort(chooseA);
    checkpoint.push_back(make_tuple("choosesort", clock(), Int::cmp_count));
    mergesort(H);
    checkpoint.push_back(make_tuple("mergesort", clock(), Int::cmp_count));
    cout << H << endl;
    for (int i = 1; i < checkpoint.size(); i++) {
      cout << get<0>(checkpoint[i]) << ": "
           << get<1>(checkpoint[i]) - get<1>(checkpoint[i - 1]) << " "
           << get<2>(checkpoint[i]) - get<2>(checkpoint[i - 1]) << endl;
    }
//    for (int i = 0; i < A.size(); i++)
//      cout << E[i] << ",";
    cout << endl;

  }

}