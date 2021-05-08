--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- @lc code=start
# Write your MySQL query statement below
select a.FirstName, a.LastName, b.City, b.State from Person a LEFT JOIN Address b ON a.PersonId = b.PersonId
-- @lc code=end

