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
  void max_heapify(vector<int>& arr, int start, int end) {
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {  //若子节点指标在范围内才做比较
      if (son + 1 <= end &&
          arr[son] < arr[son + 1])  //先比较两个子节点大小，选择最大的
        son++;
      if (arr[dad] > arr[son])  //如果父节点大于子节点代表调整完毕，直接跳出函数
        return;
      else {  //否则交换父子内容再继续子节点和孙节点比较
        swap(arr[dad], arr[son]);
        dad = son;
        son = dad * 2 + 1;
      }
    }
  }
  void heap_sort(vector<int>& arr, int len) {
    //初始化，i从最后一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--) max_heapify(arr, i, len - 1);
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) {
      swap(arr[0], arr[i]);
      max_heapify(arr, 0, i - 1);
    }
  }

  vector<int> sortArray(vector<int>& nums) {
    heap_sort(nums, nums.size());
    return nums;
  }

  void print(vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
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
  s.print(vec);
}
// @lc code=end
