package simplefactory;
/**
 * 工厂类(Creator)角色
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
