package strategy2;

import java.util.List;
/**
 * 定义一个环境工具类，可以对装有Person的list按照指定的策略来进行排序
 * @author Administrator
 *
 */
public class Environment {
	
	private SortInterface sortInterface;
	
	public Environment(SortInterface sortInterface){
		this.sortInterface = sortInterface;
	}

	public Environment(){
		
	}
	
	public void setSortInterface(SortInterface sortInterface) {
		this.sortInterface = sortInterface;
	}
	/**
	 * 对指定的list进行排序
	 * @param list
	 */
	public void Sort(List<Person> list){
		
		this.sortInterface.Sort(list);
	}
}
