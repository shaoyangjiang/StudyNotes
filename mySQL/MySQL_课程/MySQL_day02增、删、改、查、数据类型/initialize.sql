#删除数据库day02
drop database if exists day02;
#创建数据库day02
create database if not exists day02 default character set 'utf8';
#用day02
use day02;
#MySQL day02初始化数据脚本
#删除用户表
drop table if exists user;
#创建用户表
create table if not exists user(
	id int auto_increment,
	name varchar(20) not null unique,
	sex enum('0', '1') default '0',
	age int,
	work varchar(50),
	salary double(8,2),
	memo varchar(200),
	primary key(id)
);
#初始化数据
insert into user(name, sex, age, work, salary, memo) values
('张三', '0', 24, 'java', 5000.0, 'java工作者张三'),
('李四', '1', 23, 'c++', 3000, ''),
('王五', '1', 66, 'java', 4000, ''),
('赵六', '0', 41, NULL, 200, ''),
('钱七', '1', 22, NULL, 555, ''),
('小张', '0', 10, 'java', 888, ''),
('小王', '1', 23, 'c++', 999, NULL),
('Tom', '1', 20, "java", 10000, NULL);
