-- 코드를 입력하세요
select a.CART_ID from (SELECT CART_ID from CART_PRODUCTS where name ="Milk") 
a, (SELECT CART_ID from CART_PRODUCTS where name = "Yogurt") b where a.CART_ID = b.CART_ID