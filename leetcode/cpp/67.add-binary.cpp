/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i = a.size() - 1,j = b.size() - 1;
        bool flag = false;
        int tmp = 0;
        while(i >= 0 || j >= 0){
            if(i >= 0 && j >= 0)
            tmp = a[i] - '0' + b[j] - '0';
            else if(i >= 0){
                tmp = a[i] -  '0';
            } else 
                tmp = b[j] - '0';
                
           if(flag) tmp = tmp + 1;
           if(tmp == 0){
            ret = "0" + ret;
            flag = false;
           } else if (tmp == 1){
            ret = "1" + ret;
            flag = false;
           } else if (tmp == 2){
            ret = "0" + ret;
            flag = true;
           } else {
            ret = "1" + ret;
            flag = true;
           }
          if(i >= 0) --i;
          if (j >= 0) --j;
        } 
        if(flag){
            ret = "1" + ret;
        }   
        return ret;
    }
};
// @lc code=end

