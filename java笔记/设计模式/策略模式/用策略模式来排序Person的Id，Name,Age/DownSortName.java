package strategy2;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;
/**
 * Person���а���Name�Ľ���������
 * @author Administrator
 *
 */
public class DownSortName implements SortInterface, Comparator<Person> {
	/**
	 * ʹ��Collectionsֻ����Sort����������ʹ���Լ����Զ���Ƚ���
	 */
	@Override
	public void Sort(List<Person> list) {		Collections.sort(list, this);
	}
	/**
	 * ����һ��Person����ıȽ���������name���ֵ�˳��������
	 */
	@Override
	public int compare(Person o1, Person o2) {
		int result = o2.getName().compareTo(o1.getName());
		if(result == 0){
			return o1.getId() - o2.getId();
		}
		return result;
	}
	
}