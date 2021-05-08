--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--

-- @lc code=start
# Write your MySQL query statement below
select Name as Customers from (select c.Name, o.CustomerId from Customers c left join Orders o on c.ID = o.CustomerId)a where a.CustomerId is null

select c.Name as Customers from Customers c where c.Id not in (select CustomerId from Orders)
-- @lc code=end

