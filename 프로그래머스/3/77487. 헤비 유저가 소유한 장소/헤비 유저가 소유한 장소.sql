-- 코드를 입력하세요
select * from PLACES where PLACES.HOST_ID in (SELECT HOST_ID from PLACES group by HOST_ID having count(ID) >= 2);