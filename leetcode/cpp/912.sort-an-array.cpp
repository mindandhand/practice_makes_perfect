/*
 * @Author: mindandhand 1639545667@qq.com
 * @Date: 2022-03-02 15:12:54
 * @LastEditors: mindandhand 1639545667@qq.com
 * @LastEditTime: 2023-07-27 11:02:01
 * @FilePath: /practice_makes_perfect/leetcode/cpp/912.sort-an-array.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  void heapify(vector<int>& arr, int start, int end) {
    while (end >= start) {
      int dad = end;
      int child = 2 * dad + 1;
      while (child < arr.size()) {
        if (child + 1 < arr.size() && arr[child + 1] < arr[child]) ++child;
        if (arr[dad] > arr[child]) {
          swap(arr[child], arr[dad]);
        }
        dad = child;
        child = 2 * dad + 1;
      }
      --end;
    }
  }
  void heap_insert(vector<int>& arr, int value) {
    arr.push_back(value);
    int child = arr.size() - 1;
    int dad = (child - 1) / 2;
    while (child > 0 && arr[child] < arr[dad]) {
      swap(arr[child], arr[dad]);
      child = dad;
      dad = (child - 1) / 2;
    }
  }
  int heap_out(vector<int>& arr) {
    int ret = arr[0];
    if (arr.size() > 0) {
      arr[0] = arr[arr.size() - 1];
      arr.pop_back();
    }
    heapify(arr, 0, 0);

    return ret;
  }

  vector<int> sortArray(vector<int>& nums) {
    vector<int> ret;
    heapify(nums, 0, (nums.size() - 1) / 2);
    while (nums.size() > 0) {
      int val = heap_out(nums);
      ret.push_back(val);
    }
    return ret;
  }

  void print(vector<int>& nums) {
    int num = 1;
    int count = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (num == count) {
        std::cout << "num:" << num << std::endl;
        count = 1;
        num = 2 * num;
      } else {
        ++count;
      }
      std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
  }
};

int main() {
  std::vector<int> vec{5, 3, 1, 2, 4};
  Solution s;
  s.print(vec);
  auto ret = s.sortArray(vec);
  s.print(ret);
}
// @lc code=end
