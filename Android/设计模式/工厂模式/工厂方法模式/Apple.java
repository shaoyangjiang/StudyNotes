package simplefactory4;
/**
 * 具体产品角色
 * @author Administrator
 *
 */
public class Apple implements Fruit {

	@Override
	public void grow() {
		System.out.println("apple is growing");
	}

}
