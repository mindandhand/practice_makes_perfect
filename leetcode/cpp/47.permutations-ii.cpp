/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    std::map<int,bool>  accessed;
    std::set<int> members; 
    vector<vector<int> > ret;
    void findPermute(vector<int> & nums, vector<int> & path){
        for(auto i = 0; i < nums.size(); ++i){
            if(accessed[i] == true){
                continue;
            }
            path.push_back(nums[i]);
            if(path.size() == nums.size()){
                ret.push_back(path);
            } else {
                bool existed = false;
                if(members.find(nums[i]) != members.end()){
                    existed = true;
                }
                members.insert(nums[i]);
                accessed[nums[i]] = true;
                findPermute(nums, path);
                if(!existed){
                    
                }
                
            }
            
        }
    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<int> path;
        findPermute(nums, path);
        return ret;
    }
};

// @lc code=end

