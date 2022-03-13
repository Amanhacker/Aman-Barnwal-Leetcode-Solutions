# Write your MySQL query statement below

# SELECT Email 
# FROM (
#     SELECT Person.Email, COUNT(Email) as num
#     FROM Person
#     GROUP BY Email
# ) AS statistic
# WHERE num > 1;


SELECT Person.Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;
