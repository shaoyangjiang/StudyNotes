package proxy;
/**
 * 代理类
 * @author Administrator
 *
 */
public class ProxySubject extends Subject{

	private RealSubject realSubject;//代理角色内部引用了真实角色
	
	@Override
	public void request() {
		
		this.preRequest();//在真实角色操作之前所附加的操作
		
		if(realSubject == null){
			realSubject = new RealSubject();
		}
		
		realSubject.request();//真实角色所完成的事情
		
		this.subRequest();//在真实角色操作之后所附加的操作
	}

	public void preRequest(){
		System.out.println("preRequest");
	}
	
	public void subRequest(){
		System.out.println("subRequest");
	}
}
