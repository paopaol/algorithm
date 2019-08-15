#ifndef __QUICKSORT_H_
#define __QUICKSORT_H_

namespace algorithm {
// O(n*logN)
template <class forwardIt> inline void qsort_(forwardIt left, forwardIt right) {
  forwardIt left_ = left;
  forwardIt right_ = right;

  if (left_ == right_) {
    return;
  }

  forwardIt pivot = left + (right - left) / 2;
  while (left_ <= right_) {
    // skip less than *pivot
    while (*left_ < *pivot) {
      left_++;

    }
    // skip great tahn *pivot
    while (*right_ > *pivot) {
      right_--;
    }

    // maybe need swap
    if (left_ <= right_) {
      std::swap(*left_, *right_);
      if (left_ < right) {
        left_++;
      }
      if (right_ > left) {
        right_--;
      }
    }
  }

  if (left < right_) {
    qsort_(left, right_);
  }
  if (left_ < right) {
    qsort_(left_, right);
  }
}

template <class forwardIt>
inline void quickSort(forwardIt first, forwardIt last) {
  qsort_(first, last - 1);
}
} // namespace algorithm

#endif // __QUICKSORT_H_
