package simplefactory3;
/**
 * 工厂类角色
 * @author Administrator
 *
 */
public class FruitGradener {

	public static Fruit factory(String str){
		if("Apple".equals(str)){
			return new Apple();
		} else if("Orange".equals(str)){
			return new Orange();
		}
		return null;
	}
}
