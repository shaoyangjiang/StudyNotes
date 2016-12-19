package strategy2;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;
/**
 * Person类中按照Id的降序来排序
 * @author Administrator
 *
 */
public class DownSortId implements SortInterface, Comparator<Person> {
	/**
	 * 使用Collections只带的Sort来进行排序，使用自己的自定义比较器
	 */
	@Override
	public void Sort(List<Person> list) {
		// TODO Auto-generated method stub
		Collections.sort(list, this);
	}
	/**
	 * 定义一个Person对象的比较器，按照id的降序来排序
	 */
	@Override
	public int compare(Person o1, Person o2) {
		int result = o2.getId() - o1.getId();
		return result;
	}

}
