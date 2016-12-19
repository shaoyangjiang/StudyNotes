package simplefactory;
/**
 * ¿Í»§¶Ë
 * @author Administrator
 *
 */
public class Client {

	public static void main(String[] args) {
		Product ProductA= Creator.createProduct("A");
		System.out.println(ProductA.getClass().getName());
		
		Product ProductB = Creator.createProduct("B");
		System.out.println(ProductB.getClass().getName());
	}
}
