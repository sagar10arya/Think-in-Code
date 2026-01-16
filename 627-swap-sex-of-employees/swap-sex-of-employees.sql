-- update salary
-- set sex = CASE
--         when sex = "m" then "f"
--         else "m"
--         end;

-- ascii math trick
UPDATE Salary
SET sex = CHAR(ASCII('m') + ASCII('f') - ASCII(sex));