package proxy;
/**
 * ��ʵ��
 * @author Administrator
 *
 */
public class RealSubject extends Subject{

	@Override
	public void request() {
		System.out.println("this is RealSubject");
	}

	
}
