package strategy2;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;
/**
 * Person���а���Id������������
 * @author Administrator
 *
 */
public class UpSortId implements SortInterface, Comparator<Person> {
	/**
	 * ʹ��Collectionsֻ����Sort����������ʹ���Լ����Զ���Ƚ���
	 */
	@Override
	public void Sort(List<Person> list) {
		// TODO Auto-generated method stub		Collections.sort(list, this);
	}
	/**
	 * ����һ��Person����ıȽ���������id������������
	 */
	@Override
	public int compare(Person o1, Person o2) {
		int result = o1.getId() - o2.getId();
		return result;
	}

	
}
