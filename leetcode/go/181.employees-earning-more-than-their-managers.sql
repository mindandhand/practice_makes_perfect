--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--

-- @lc code=start
# Write your MySQL query statement below
select e.Name as Employee from Employee e, Employee f where e.ManagerId = f.Id and e.Salary > f.Salary
-- @lc code=end

