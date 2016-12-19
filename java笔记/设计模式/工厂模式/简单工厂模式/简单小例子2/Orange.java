package simplefactory3;
/**
 * 具体产品类
 * @author Administrator
 *
 */
public class Orange implements Fruit {

	@Override
	public void grow() {
		System.out.println("orange is growing");
	}

}
