#ɾ�����ݿ�day02
drop database if exists day02;
#�������ݿ�day02
create database if not exists day02 default character set 'utf8';
#��day02
use day02;
#MySQL day02��ʼ�����ݽű�
#ɾ���û���
drop table if exists user;
#�����û���
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
#��ʼ������
insert into user(name, sex, age, work, salary, memo) values
('����', '0', 24, 'java', 5000.0, 'java����������'),
('����', '1', 23, 'c++', 3000, ''),
('����', '1', 66, 'java', 4000, ''),
('����', '0', 41, NULL, 200, ''),
('Ǯ��', '1', 22, NULL, 555, ''),
('С��', '0', 10, 'java', 888, ''),
('С��', '1', 23, 'c++', 999, NULL),
('Tom', '1', 20, "java", 10000, NULL);
