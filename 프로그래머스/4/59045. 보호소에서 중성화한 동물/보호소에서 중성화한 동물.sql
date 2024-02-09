-- 코드를 입력하세요
select b.ANIMAL_ID, b.ANIMAL_TYPE, b.NAME from
(SELECT * from ANIMAL_OUTS 
    where SEX_UPON_OUTCOME = "Neutered Male" OR
          SEX_UPON_OUTCOME = "Spayed Female") a,
(SELECT * from ANIMAL_INS 
    where SEX_UPON_INTAKE != "Neutered Male" and
          SEX_UPON_INTAKE != "Spayed Female") b where a.ANIMAL_ID = b.ANIMAL_ID
          order by a.ANIMAL_ID;