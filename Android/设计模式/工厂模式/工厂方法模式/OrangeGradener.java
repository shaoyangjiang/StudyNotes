package simplefactory4;
/**
 * ���幤����ɫ
 * @author Administrator
 *
 */
public class OrangeGradener implements FruitGradener {

	@Override
	public Fruit factory() {
		return new Orange();
	}

}
