/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int> > ret;
       for(size_t i = 0; i < candidates.size(); ++i){
           if(target > candidates[i]){
            auto child_ret = combinationSum(candidates, target - candidates[i]);
            for(size_t j=0 ; j < child_ret.size(); ++j){
                child_ret[j].insert(child_ret[j].begin(),candidates[i]);
                ret.push_back(child_ret[j]);
            }
           } else if(target == candidates[i]){
               vector<int> res{candidates[i]};
               ret.push_back(res);
           }
       }
       return ret;
    }
};
int main(){
    vector<int> nums{2,3,6,7};
    Solution s;
    auto sums = s.combinationSum(nums, 7);
    for(int i = 0; i < sums.size(); ++i){
        std::cout << std::endl;
        for(size_t j = 0; j < sums[i].size(); ++j ){
            std::cout << sums[i][j] << " ";
        }
    } 
}
// @lc code=end

