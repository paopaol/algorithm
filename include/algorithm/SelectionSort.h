#ifndef __SELECTIONSORT_H_
#define __SELECTIONSORT_H_

#include <algorithm>
#include <iterator>
#include <vector>

namespace algorithm {
template <typename forwardIt>
forwardIt findMin(forwardIt first, forwardIt last) {
  if (first == last) {
    return first;
  }
  forwardIt min = first;
  for (auto e = first; e != last; e++) {
    if (*min > *e) {
      min = e;
    }
  }
  return min;
}

/// O(log(n * n))
template <class T> void selectionSort(std::vector<T> &v) {
  std::vector<T> vn;
  while (!v.empty()) {
    auto min = findMin(v.begin(), v.end());
    vn.push_back(*min);
    v.erase(min);
  }
  v = vn;
}
} // namespace algorithm

#endif // __SELECTIONSORT_H_
