#ɾ�����ݿ�
drop database if exists day03;
#�������ݿ�
create database if not exists day03 default character set 'utf8';
use day03;
#�����༶��Ϣ��
create table classes(
	id int auto_increment,
	name varchar(20),
	constraint pk_classes_id primary key(id)
);
#����ѧ����Ϣ��
create table student(
	id int auto_increment,
	name varchar(20) not null,
	age int,
	sex enum('��', 'Ů'),
	classes_id int,
	constraint pk_student_id primary key(id)
	#,constraint fk_classes_id foreign key(classes_id) references classes(id)
);
#��ʼ������
insert into classes(name) values 
('��һ�༶'),
('�ڶ��༶'),
('�����༶');
#
insert into student(name, age, sex, classes_id) values
('����', 20, '��', 1),
('����', 21, 'Ů', 2),
('����', 25, '��', 3),
('����', 23, '��', 1),
('Ǯ��', 26, 'Ů', 2),
('С��', 22, '��', 2),
('Tom', 28, '��', 3),
('Jons', 23, 'Ů', NULL);
