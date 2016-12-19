package proxy;
/**
 * ������
 * @author Administrator
 *
 */
public class ProxySubject extends Subject{

	private RealSubject realSubject;//�����ɫ�ڲ���������ʵ��ɫ
	
	@Override
	public void request() {
		
		this.preRequest();//����ʵ��ɫ����֮ǰ�����ӵĲ���
		
		if(realSubject == null){
			realSubject = new RealSubject();
		}
		
		realSubject.request();//��ʵ��ɫ����ɵ�����
		
		this.subRequest();//����ʵ��ɫ����֮�������ӵĲ���
	}

	public void preRequest(){
		System.out.println("preRequest");
	}
	
	public void subRequest(){
		System.out.println("subRequest");
	}
}
