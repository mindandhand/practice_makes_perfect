--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--

-- @lc code=start
# Write your MySQL query statement below
select  ifnull((select distinct Salary from Employee order by Salary desc limit 1,1),null) as SecondHighestSalary
-- @lc code=end

