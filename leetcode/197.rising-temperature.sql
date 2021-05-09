--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--

-- @lc code=start
# Write your MySQL query statement below
select w.id from Weather w, Weather x where date_sub(w.recordDate, interval 1 day)=x.recordDate and w.temperature > x.temperature
-- @lc code=end

