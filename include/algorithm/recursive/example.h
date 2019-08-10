#ifndef __EXAMPLE_H_
#define __EXAMPLE_H_

#include <algorithm>
#include <iterator>
#include <vector>

namespace algorithm {
inline int findMaxSquare(int w, int h) {
  int longest = std::max(w, h);
  int shortest = std::min(w, h);

  if (longest % shortest == 0) {
    return shortest;
  }
  return findMaxSquare(shortest, longest - shortest);
}

template <class forwardIt>
inline int sumArray(forwardIt first, forwardIt last) {
  if (first == last) {
    return 0;
  }
  return *first + sumArray(++first, last);
}
} // namespace algorithm

#endif // __EXAMPLE_H_
