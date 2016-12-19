package simplefactory4;
/**
 * 具体产品角色
 * @author Administrator
 *
 */
public class Orange implements Fruit {

	@Override
	public void grow() {
		System.out.println("orange is growing");
	}

}
