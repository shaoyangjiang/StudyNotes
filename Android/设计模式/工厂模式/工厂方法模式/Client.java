package simplefactory4;
/**
 * ¿Í»§¶Ë
 * @author Administrator
 *
 */
public class Client {

	public static void main(String[] args) {
		FruitGradener appleGradener = new AppleGradener();
		Fruit apple = appleGradener.factory();
		apple.grow();
	}
}
