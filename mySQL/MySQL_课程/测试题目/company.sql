DROP DATABASE IF EXISTS `companydb`;
CREATE DATABASE `companydb`;

USE `companydb`;

CREATE TABLE `employee` (
	`num` INT AUTO_INCREMENT PRIMARY KEY,
	`name` VARCHAR(20) NOT NULL,
	`sex` CHAR(1) NOT NULL,
	`age` INT NOT NULL,
	`departmentno` VARCHAR(40)
);

CREATE TABLE `wage`(
	`no` INT PRIMARY KEY,
	`amount` INT
);

CREATE TABLE `attend` (
	`num` INT,
	`no` INT,
	`attendance` INT,

	#constraint num_no_key primary key(`num`, `no`)
	CONSTRAINT FOREIGN KEY num_key(`num`) REFERENCES `employee`(`num`),
	CONSTRAINT FOREIGN KEY no_key(`no`) REFERENCES `attend`(`no`)
);

INSERT INTO `employee` VALUES
(NULL, 'zhangsan', 'M', 23, 'Personnel department'),
(NULL, 'lisi', 'M', 43, 'Treasury department'),
(NULL, 'wangwu', 'F', 27, 'Marketing Department '),
(NULL, 'hello', 'M', 20, 'Treasury department'),
(NULL, 'world', 'F', 78, 'Personnel department'),
(NULL, 'welcome', 'F', 19, 'Marketing Department'),
(NULL, 'google', 'M', 32, 'Product department'),
(NULL, 'baidu', 'F', 26, 'Product department');


INSERT INTO `wage` VALUES 
(1, 4000),
(2, 6000),
(3, 8000),
(4, 2000);

INSERT INTO `attend` VALUES
(1, 1, 7),
(2, 4, 10),
(3, 1, 9),
(4, 2, 13),
(5, 4, 10),
(6, 3, 8),
(7, 1, 10),
(8, 3, 10);










