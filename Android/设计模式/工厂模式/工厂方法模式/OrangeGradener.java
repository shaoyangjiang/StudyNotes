package simplefactory4;
/**
 * 具体工厂角色
 * @author Administrator
 *
 */
public class OrangeGradener implements FruitGradener {

	@Override
	public Fruit factory() {
		return new Orange();
	}

}
