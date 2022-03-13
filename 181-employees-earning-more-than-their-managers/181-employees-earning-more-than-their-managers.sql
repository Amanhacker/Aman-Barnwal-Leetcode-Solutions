# Write your MySQL query statement below

SELECT a.Name AS 'Employee'
FROM Employee AS a
JOIN Employee AS b
ON a.ManagerId = b.Id AND a.salary > b.salary;