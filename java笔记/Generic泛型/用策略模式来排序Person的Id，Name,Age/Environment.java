package strategy2;

import java.util.List;
/**
 * ����һ�����������࣬���Զ�װ��Person��list����ָ���Ĳ�������������
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
	 * ��ָ����list��������
	 * @param list
	 */
	public void Sort(List<Person> list){
		
		this.sortInterface.Sort(list);
	}
}
