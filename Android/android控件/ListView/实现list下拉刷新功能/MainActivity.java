package com.tiantian.test;

import java.util.Arrays;
import java.util.LinkedList;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.widget.ArrayAdapter;

import com.tiantian.test.PullRefreshListView.OnRefreshListener;

public class MainActivity extends Activity {
	private PullRefreshListView refreshList;

	private LinkedList<String> list;

	private String[] mStrings = { "Abbaye de Belloc",
			"Abbaye du Mont des Cats", "Abertam", "Abondance", "Ackawi",
			"Acorn", "Adelost", "Affidelice au Chablis", "Afuega'l Pitu",
			"Airag", "Airedale", "Aisy Cendre", "Allgauer Emmentaler" };

	private int i;
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		refreshList = (PullRefreshListView) findViewById(R.id.refreshList);
		//设置刷新监听器
		refreshList.setOnRefreshListener(new OnRefreshListener() {
			
			@Override
			public void onRefresh() {
				//启动异步任务来实现刷新功能
				new GetDataTask().execute();
			}
		});
		
		list = new LinkedList<String>();
		list.addAll(Arrays.asList(mStrings));//把测试数据的mstrings数组转成List加到list中

		ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
				android.R.layout.simple_list_item_1, list);
		
		refreshList.setAdapter(adapter);

	}
	/**
	 * 改异步任务实现刷新功能
	 * @author com.tiantian
	 */
	private class GetDataTask extends AsyncTask<Void, Void, Integer>{

		@Override
		protected Integer doInBackground(Void... params) {
			//加入要执行的语句
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			return 1;
		}
		
		@Override
		protected void onPostExecute(Integer result) {
			super.onPostExecute(result);
			list.addFirst("刷新" + i++); //把刷新的内容添加到最上面
			refreshList.onRefreshComplete();//完成刷新功能
		}
		
	}
	
	
	
	
}