# Write your MySQL query statement below
-- select id , 
--     if(p_id is null , "Root", 
--         if(id not in (select distinct p_id from Tree where p_id is not null) , "Leaf", "Inner")
--     ) as type
-- from Tree
# Write your MySQL query statement below

select id, 
    case 
        when p_id  is null then 'Root'
        when id  In (select  p_id from tree where p_id is not null) then 'Inner'
        else 'Leaf'
    end as  type  
from Tree order by id