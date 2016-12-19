#ɾ�����ݿ�
drop database if exists day05;
#�������ݿ�
create database if not exists day05 default character set 'utf8';
use day05;
#������ʾ��
CREATE TABLE t(s1 int);
#��ʼ������
INSERT INTO t(s1) VALUES(5);
#���������Ա�
#����ѧ����Ϣ��
drop table if exists student;
create table student(
	id int auto_increment,
	name varchar(20) not null,
	age int,
	constraint pk_student_id primary key(id)
);
#����ѧ����Ϣ���ݱ�
drop table if exists student_bak;
create table student_bak like student;
#����ѧ����Ϣ��־��
drop table if exists student_log;
CREATE TABLE student_log(
	id int auto_increment primary key,
	stuname varchar(20),
	logtime datetime,
	operatortype varchar(255),
	logmemo varchar(255)
);
#����ѧ����Ϣ�޸���־��
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
	

