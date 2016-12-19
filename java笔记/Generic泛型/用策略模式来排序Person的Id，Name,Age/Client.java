package strategy2;

import java.util.ArrayList;
import java.util.List;
/**
 * �����࣬�ֱ�ʵ���˰����ֵ�������Id��������
 * @author Administrator
 *
 */
public class Client {
	
	public static void main(String[] args) {
		//����5��person����
		Person p1 = new Person(1,"zhangsan",20);
		Person p2 = new Person(2,"lisi",28);
		Person p3 = new Person(3,"shaoyangjiang",18);
		Person p4 = new Person(4,"zhangsan",29);
		Person p5 = new Person(5,"wangjie",17);
		//��person����ŵ���������˷���
		List<Person> list = new ArrayList<Person>();
		list.add(p1);
		list.add(p2);
		list.add(p3);
		list.add(p4);
		list.add(p5);
		//��������������
		UpSortName up = new UpSortName();
		Environment env = new Environment(up);
		env.Sort(list);
		
		System.out.println("�������ֵ��ֵ�˳��������������ͬ����id������������");
		for(int i = 0;i < list.size();i++){
			Person p = list.get(i);
			System.out.println("id:"+p.getId()+",name:"+p.getName()+",age:"+p.getAge());
		}
		//�����ֽ�������
		DownSortName down = new DownSortName();
		env = new Environment(down);
		env.Sort(list);
		System.out.println("�������ֵ��ֵ併��������������ͬ����id������������");
		for(int i = 0;i < list.size();i++){
			Person p = list.get(i);
			System.out.println("id:"+p.getId()+",name:"+p.getName()+",age:"+p.getAge());
		}
		//��ѧ����������
		UpSortId upId = new UpSortId();
		env = new Environment(upId);
		env.Sort(list);
		System.out.println("����id������������");
		for(int i = 0;i < list.size();i++){
			Person p = list.get(i);
			System.out.println("id:"+p.getId()+",name:"+p.getName()+",age:"+p.getAge());
		}
		
		//��ѧ�Ž�������
		DownSortId downId = new DownSortId();
		env = new Environment(downId);
		env.Sort(list);
		System.out.println("����id�Ľ���������");
		for(int i = 0;i < list.size();i++){
			Person p = list.get(i);
			System.out.println("id:"+p.getId()+",name:"+p.getName()+",age:"+p.getAge());
		}
		
	}
}
