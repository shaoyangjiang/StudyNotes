USE `companydb`;

#(1)
SELECT a.`num`, e.`name`
FROM `employee` e 
LEFT JOIN `attend` a ON e.`num` = a.`num`
LEFT JOIN `wage` w ON a.`no` = w.`no`
WHERE w.`amount` = 8000;


#(2)
SELECT e.`name`, a.`attendance`
FROM `attend` a
LEFT JOIN `employee` e ON a.`num` = e.`num`
WHERE e.`name` = 'zhangsan';


#(3)

#(4)
SELECT e.`num`, e.`name`, e.`sex`, e.`age`, e.`departmentno`
FROM `employee` e
LEFT JOIN `attend` a ON a.`num` = e.`num`
LEFT JOIN `wage` w ON w.`no` = a.`no`
WHERE a.`attendance` = 10 AND w.`amount` < 2500;







