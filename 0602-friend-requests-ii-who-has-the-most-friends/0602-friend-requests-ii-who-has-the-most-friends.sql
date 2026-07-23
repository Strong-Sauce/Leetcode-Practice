# Write your MySQL query statement below
select id, count(*) as num
from (
    select requester_id as id
    from requestAccepted

    union all

    select accepter_id as id
    from requestAccepted
) as friends 
group by id
order by num desc
limit 1;
