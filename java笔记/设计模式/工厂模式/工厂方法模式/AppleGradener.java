package simplefactory4;
/**
 * ���幤����ɫ
 * @author Administrator
 *
 */
public class AppleGradener implements FruitGradener {

	@Override
	public Fruit factory() {
		return new Apple();
	}

}
