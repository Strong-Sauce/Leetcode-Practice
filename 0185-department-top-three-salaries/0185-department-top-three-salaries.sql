# Write your MySQL query statement below
select d.name as Department , e.name as Employee , e.salary as Salary
from Department d
left join (
    select *,
        dense_rank() 
        over(partition by departmentId order by salary desc) as rnk
    from Employee
 ) e
on d.id = e.departmentId 
where e.rnk < 4;