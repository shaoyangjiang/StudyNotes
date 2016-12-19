#create database `mysqldbtest` default charset utf8;

USE `mysqldbtest`;

#CREATE TABLE `student` (
#	stu_num INT AUTO_INCREMENT PRIMARY KEY,
#	stu_name VARCHAR(10),
#	stu_age INT,
#	stu_birth DATE
#);

#INSERT INTO `student` VALUES(NULL, 'ysq', 22, '1990-06-05');

#SHOW COLUMNS FROM `student`;

#ALTER TABLE `student` ADD stu_gender VARCHAR(10) DEFAULT 'M' AFTER stu_age;

#SELECT * FROM `student`;

#SELECT * FROM `student` WHERE stu_name LIKE '%王%';


#ALTER TABLE `student` ADD stu_extra VARCHAR(20) AFTER stu_birth;

#ALTER TABLE `student` DROP stu_extra;

#ALTER TABLE `student` CHANGE stu_extra stu_ex VARCHAR(20);

#ALTER TABLE `stu` RENAME `student`;

#CREATE TABLE `person`(
#	person_id INT AUTO_INCREMENT PRIMARY KEY,
#	person_name VARCHAR(10)
#);

#DROP TABLE `person`;

#INSERT INTO `student` VALUES
#(NULL, 'zhangsan', 23, 'F', '1990-01-20', ''),
#(NULL, 'lisi', 21, 'M', '1992-04-20', ''),
#(NULL, 'wangyu', 19, 'M', '1994-02-14', ''),
#(NULL, 'zhaoliu', 20, 'F', '1993-06-05', '');

#ALTER TABLE `student` MODIFY stu_name VARCHAR(20) NOT NULL;

#ALTER TABLE `student` CHANGE stu_name stu_name VARCHAR(20) NULL;

#SELECT * FROM `student`;


#CREATE TABLE `user`(
#	id INT AUTO_INCREMENT PRIMARY KEY,
#	username VARCHAR(20),
#	password VARCHAR(20),
#	CONSTRAINT uk_name_pwd		UNIQUE(username, password)
#);

#SHOW CREATE TABLE `user`;


#ALTER TABLE `user` DROP INDEX uk_name_pwd;


#ALTER TABLE `user` ADD CONSTRAINT uk_name_pwd UNIQUE(`username`, `password`);

#ALTER TABLE `user` ADD UNIQUE(`username`, `password`);

#ALTER TABLE `user` DROP KEY `username`;

#ALTER TABLE `user` DROP KEY `uk_name_pwd`;
#SHOW CREATE TABLE `user`;


#CREATE TABLE `book`(
#	book_id INT PRIMARY KEY AUTO_INCREMENT,
#	book_name VARCHAR(20),
#	book_author VARCHAR(20)
#);


/*
DROP TABLE IF EXISTS `classes`;
DROP TABLE IF EXISTS `stu`;


CREATE TABLE `classes` (
    `id` INT,
    `name` VARCHAR(20),
    `number` INT,
    PRIMARY KEY (`id`)
);

CREATE TABLE `stu` (
    `id` INT AUTO_INCREMENT PRIMARY KEY,
    `name` VARCHAR(20),
    `classes_name` VARCHAR(20),
    `classes_number` INT,
    FOREIGN KEY (`classes_name` , `classes_number`)
        REFERENCES `classes` (`name` , `number`)
        ON DELETE SET NULL
);

INSERT INTO `classes` VALUES(1, 'class1', 25),(2, 'class2', 30);

INSERT INTO `stu` VALUES
(NULL, 'wangjie', 'class1', 25),
(NULL, 'ysq', 'class1', 25),
(NULL, 'wj', 'class2', 30);
*/

#SELECT * FROM `stu`, `classes`
#WHERE `stu`.`classes_name` = `classes`.`name`;

/*
select s.`name`, c.`name`
from `stu` s, `classes` c
where s.`classes_name` = c.`name` and s.`id` = 2;
*/

#select * from `stu` join `classes` on `stu`.classes_number = classes.number where number < 30;

#select * from `stu` s right outer join `classes` c on s.`classes_number` = c.`number`;

#select * from `stu` s where s.classes_number in (select c.number from classes c);


select * from `stu` s where s.classes_number = (select c.number from classes c where c.id = 1);


