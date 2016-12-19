#删除数据库
drop database if exists day03;
#创建数据库
create database if not exists day03 default character set 'utf8';
use day03;
#创建班级信息表
create table classes(
	id int auto_increment,
	name varchar(20),
	constraint pk_classes_id primary key(id)
);
#创建学生信息表
create table student(
	id int auto_increment,
	name varchar(20) not null,
	age int,
	sex enum('男', '女'),
	classes_id int,
	constraint pk_student_id primary key(id)
	#,constraint fk_classes_id foreign key(classes_id) references classes(id)
);
#初始化数据
insert into classes(name) values 
('第一班级'),
('第二班级'),
('第三班级');
#
insert into student(name, age, sex, classes_id) values
('张三', 20, '男', 1),
('李四', 21, '女', 2),
('王五', 25, '男', 3),
('赵六', 23, '男', 1),
('钱七', 26, '女', 2),
('小王', 22, '男', 2),
('Tom', 28, '男', 3),
('Jons', 23, '女', NULL);
