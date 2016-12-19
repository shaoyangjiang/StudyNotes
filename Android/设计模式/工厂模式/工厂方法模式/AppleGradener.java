package simplefactory4;
/**
 * 具体工厂角色
 * @author Administrator
 *
 */
public class AppleGradener implements FruitGradener {

	@Override
	public Fruit factory() {
		return new Apple();
	}

}
