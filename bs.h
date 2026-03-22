#pragma once

#include "lc.h"

namespace Binary_search {
int inline bs_left(vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size();
  while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] >= target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  if (right >= nums.size() || right < 0 || nums[right] != target)
    return -1;
  return right;
}

int inline bs_right(vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size();
  while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] <= target) {
      left = mid + 1;

    } else {
      right = mid;
    }
  }
  if (right - 1 >= nums.size() || right - 1 < 0 || nums[right - 1] != target)
    return -1;
  return right - 1;
}

}; // namespace Binary_search

namespace Sliding_window {
// 滑动窗口算法伪码框架
void slidingWindow(string s) {
    // 用合适的数据结构记录窗口中的数据，根据具体场景变通
    // 比如说，我想记录窗口中元素出现的次数，就用 map
    // 如果我想记录窗口中的元素和，就可以只用一个 int
    auto window  

    int left = 0, right = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        window.add(c);
        // 增大窗口
        right++;

        // 进行窗口内数据的一系列更新
        
        // *** debug 输出的位置 ***
        

        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            window.remove(d);
            // 缩小窗口
            left++;

            // 进行窗口内数据的一系列更新
            
        }
    }
}
};