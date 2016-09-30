//
// Created by sun on 16-9-26.
//

#ifndef BASIC_ALGORITHMS_UTILS_H
#define BASIC_ALGORITHMS_UTILS_H

#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cassert>
#include <stack>
#include <list>

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vv) {
  out << "[";
  if (vv.size() > 0)
    out << vv[0];
  for (int i = 1; i < vv.size(); i++) {
    out << "," << vv[i];
  }
  out << "]";
  return out;
}
#endif //BASIC_ALGORITHMS_UTILS_H
