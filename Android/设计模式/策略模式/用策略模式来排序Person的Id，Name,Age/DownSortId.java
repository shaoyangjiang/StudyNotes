package strategy2;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;
/**
 * Person���а���Id�Ľ���������
 * @author Administrator
 *
 */
public class DownSortId implements SortInterface, Comparator<Person> {
	/**
	 * ʹ��Collectionsֻ����Sort����������ʹ���Լ����Զ���Ƚ���
	 */
	@Override
	public void Sort(List<Person> list) {
		// TODO Auto-generated method stub
		Collections.sort(list, this);
	}
	/**
	 * ����һ��Person����ıȽ���������id�Ľ���������
	 */
	@Override
	public int compare(Person o1, Person o2) {
		int result = o2.getId() - o1.getId();
		return result;
	}

}
