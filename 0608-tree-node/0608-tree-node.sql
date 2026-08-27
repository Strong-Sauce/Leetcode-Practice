# Write your MySQL query statement below
select id , 
    if(p_id is null , "Root", 
        if(id not in (select distinct p_id from Tree where p_id is not null) , "Leaf", "Inner")
    ) as type
from Tree