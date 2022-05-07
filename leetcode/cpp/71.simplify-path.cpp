/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  string simplifyPath(string path) {
    std::string ret, tmp;
    size_t start = 0;
    size_t pos;
    list<string> path_list;
    while (start < path.size()) {
      while (path[start] == '/') ++start;
      if (start >= path.size()) break;
      pos = path.find_first_of('/', start);
      tmp = path.substr(start, pos - start);
      if (tmp == ".") {
      } else if (tmp == "..") {
        if (path_list.size() > 0) path_list.pop_back();
      } else {
        path_list.push_back(tmp);
      }
      start = pos;
    }
    if (path_list.size() == 0) {
      ret = "/";
    } else {
      while (path_list.size() > 0) {
        ret.append("/").append(path_list.front());
        path_list.pop_front();
      }
    }
    return ret;
  }
};
int main() {
  Solution s;
  std::cout << s.simplifyPath("/////root/cat/") << std::endl;
  std::cout << s.simplifyPath("/../") << std::endl;
}
// @lc code=end
