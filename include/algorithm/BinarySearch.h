#ifndef __BINARY_SEARCH_H_
#define __BINARY_SEARCH_H_

#include <vector>

namespace algorithm {
/// O(log n)
template <typename T>
 inline bool binarySearch(const std::vector<T> &list,
                                              const T &t) {
  size_t low = 0;
  size_t high = list.size() - 1;

  while (low <= high) {
    size_t mid = (low + high) / 2;
    const T &guess = list[mid];

    if (guess == t) {
      return true;
    } else if (t < guess) {
      // too big
      high = mid - 1;
    } else {
      // too small
      low = mid + 1;
    }
  }
  return false;
}
} // namespace algorithm

#endif // __BINARY_SEARCH_H_
