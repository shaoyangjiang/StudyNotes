#删除数据库
drop database if exists day05;
#创建数据库
create database if not exists day05 default character set 'utf8';
use day05;
#创建演示表
CREATE TABLE t(s1 int);
#初始化数据
INSERT INTO t(s1) VALUES(5);
#触发器测试表
#创建学生信息表
drop table if exists student;
create table student(
	id int auto_increment,
	name varchar(20) not null,
	age int,
	constraint pk_student_id primary key(id)
);
#创建学生信息备份表
drop table if exists student_bak;
create table student_bak like student;
#创建学生信息日志表
drop table if exists student_log;
CREATE TABLE student_log(
	id int auto_increment primary key,
	stuname varchar(20),
	logtime datetime,
	operatortype varchar(255),
	logmemo varchar(255)
);
#创建学生信息修改日志表
DROP TABLE IF EXISTS student_update_log;
CREATE TABLE student_update_log(
	id int auto_increment primary key,
	stuid int not null,
	oldname varchar(255),
	newname varchar(255),
	oldage int,
	newage int,
	logtime datetime,
	logmemo varchar(255)
);
	

