package simplefactory3;
/**
 * �ͻ���
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
