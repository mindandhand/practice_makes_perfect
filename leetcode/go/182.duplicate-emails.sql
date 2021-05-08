--
-- @lc app=leetcode id=182 lang=mysql
--
-- [182] Duplicate Emails
--

-- @lc code=start
# Write your MySQL query statement below
select Email from Person p group by p.Email having count(Email) > 1
-- @lc code=end

