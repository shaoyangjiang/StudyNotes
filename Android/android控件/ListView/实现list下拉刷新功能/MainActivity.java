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
		//����ˢ�¼�����
		refreshList.setOnRefreshListener(new OnRefreshListener() {
			
			@Override
			public void onRefresh() {
				//�����첽������ʵ��ˢ�¹���
				new GetDataTask().execute();
			}
		});
		
		list = new LinkedList<String>();
		list.addAll(Arrays.asList(mStrings));//�Ѳ������ݵ�mstrings����ת��List�ӵ�list��

		ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
				android.R.layout.simple_list_item_1, list);
		
		refreshList.setAdapter(adapter);

	}
	/**
	 * ���첽����ʵ��ˢ�¹���
	 * @author com.tiantian
	 */
	private class GetDataTask extends AsyncTask<Void, Void, Integer>{

		@Override
		protected Integer doInBackground(Void... params) {
			//����Ҫִ�е����
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
			list.addFirst("ˢ��" + i++); //��ˢ�µ�������ӵ�������
			refreshList.onRefreshComplete();//���ˢ�¹���
		}
		
	}
	
	
	
	
}