package simplefactory;
/**
 * ������(Creator)��ɫ
 * @author Administrator
 *
 */
public class Creator {

	public static Product createProduct(String str){
		if("A".equals(str)){
			return new ConcreatProductA();
		}
		if("B".equals(str)){
			return new ConcreateProductB();
		}
		return null;
	}
}
