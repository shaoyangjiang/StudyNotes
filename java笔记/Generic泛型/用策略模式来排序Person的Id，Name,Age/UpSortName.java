package strategy2;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;
/**
 * Person���а���Name������������
 * @author Administrator
 *
 */
public class UpSortName implements SortInterface, Comparator<Person> {
	/**
	 * ʹ��Collectionsֻ����Sort����������ʹ���Լ����Զ���Ƚ���
	 */
	@Override
	public void Sort(List<Person> list) {
		Collections.sort(list, this);
	}
	/**
	 * ����һ��Person����ıȽ���������name���ֵ�˳��������
	 */
	@Override
	public int compare(Person o1, Person o2) {
		int result = o1.getName().compareTo(o2.getName());
		
		if(0 == result){
			return o1.getId() - o2.getId();
		}
		return result;
	}

}
