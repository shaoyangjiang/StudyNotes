package strategy2;

import java.util.ArrayList;
import java.util.List;
/**
 * 测试类，分别实现了按名字的升降序，Id的升降序
 * @author Administrator
 *
 */
public class Client {
	
	public static void main(String[] args) {
		//生成5个person对象
		Person p1 = new Person(1,"zhangsan",20);
		Person p2 = new Person(2,"lisi",28);
		Person p3 = new Person(3,"shaoyangjiang",18);
		Person p4 = new Person(4,"zhangsan",29);
		Person p5 = new Person(5,"wangjie",17);
		//把person对象放到集合里，用了泛型
		List<Person> list = new ArrayList<Person>();
		list.add(p1);
		list.add(p2);
		list.add(p3);
		list.add(p4);
		list.add(p5);
		//按名字升序排序
		UpSortName up = new UpSortName();
		Environment env = new Environment(up);
		env.Sort(list);
		
		System.out.println("按照名字的字典顺序来排序，名字相同按照id的升序来排序");
		for(int i = 0;i < list.size();i++){
			Person p = list.get(i);
			System.out.println("id:"+p.getId()+",name:"+p.getName()+",age:"+p.getAge());
		}
		//按名字降序排序
		DownSortName down = new DownSortName();
		env = new Environment(down);
		env.Sort(list);
		System.out.println("按照名字的字典降序来排序，名字相同按照id的升序来排序");
		for(int i = 0;i < list.size();i++){
			Person p = list.get(i);
			System.out.println("id:"+p.getId()+",name:"+p.getName()+",age:"+p.getAge());
		}
		//按学号升序排序
		UpSortId upId = new UpSortId();
		env = new Environment(upId);
		env.Sort(list);
		System.out.println("按照id的升序来排序");
		for(int i = 0;i < list.size();i++){
			Person p = list.get(i);
			System.out.println("id:"+p.getId()+",name:"+p.getName()+",age:"+p.getAge());
		}
		
		//按学号降序排序
		DownSortId downId = new DownSortId();
		env = new Environment(downId);
		env.Sort(list);
		System.out.println("按照id的降序来排序");
		for(int i = 0;i < list.size();i++){
			Person p = list.get(i);
			System.out.println("id:"+p.getId()+",name:"+p.getName()+",age:"+p.getAge());
		}
		
	}
}
