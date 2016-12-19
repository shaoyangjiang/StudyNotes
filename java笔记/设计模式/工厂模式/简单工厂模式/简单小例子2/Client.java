package simplefactory3;
/**
 * ¿Í»§¶Ë
 * @author Administrator
 *
 */
public class Client {

	public static void main(String[] args) {
		Fruit apple = FruitGradener.factory("Apple");
		apple.grow();
		
		Fruit orange = FruitGradener.factory("Orange");
		orange.grow();
	}
}
