/*
 * Copyright (C) nonobank.com ��ICP��13003999��
 *                               ��Ȩ���У�ŵŵ����
 *						        �ͻ����ߣ�4000-646-668
 * Created on 2013-4-1 ����3:16:11 
 */
package com.nonobank.app.activity.messageCenter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;
import android.widget.AdapterView.OnItemClickListener;

import com.nonobank.app.adapter.MessageReadListAdapter;
import com.nonobank.app.model.R;

 
/**
 * Document Instruction
 * @author shaoyangjiang
 * Created on 2013-4-1 ����3:16:11
 */
public class MessageRead extends Activity {
	private ListView messageReadLv;
	private List<HashMap<String,Object>> messageReadList = new ArrayList<HashMap<String,Object>>();
	private MessageReadListAdapter adapter;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.message_read);
		messageReadLv = (ListView) findViewById(R.id.messageReadLv);
		adapter = new MessageReadListAdapter(this, messageReadList);
		showListView();
		messageReadLv.setAdapter(adapter);
		messageReadLv.setOnItemClickListener(MessageReadItemClickListener);
	}
	
	/*
	 * �����Ժ�Ҫ�ӷ�����������
	 */
	private void showListView(){
		HashMap<String, Object> map = new HashMap<String, Object>();
		
		map.put("_messageNumber", "123456");
		map.put("_messageTime", "����9��10��");
		map.put("_messageBody", "ŵŵ���͵ľ�Ӣ�ǣ�������Ϻ�");
		messageReadList.add(map);
		
		map = new HashMap<String, Object>();
		map.put("_messageNumber", "23454523");
		map.put("_messageTime", "����9��10��");
		map.put("_messageBody", "�ã��ܺã��ǳ���");
		messageReadList.add(map);
		
		map = new HashMap<String, Object>();
		map.put("_messageNumber", "123456");
		map.put("_messageTime", "����11��12��");
		map.put("_messageBody", "Ҫ�����ˣ�����");
		messageReadList.add(map);
	}
	
	/*
	 * ��ÿ���Ѷ���Ϣitem���м���
	 */
	private OnItemClickListener MessageReadItemClickListener = new OnItemClickListener() {

		@Override
		public void onItemClick(AdapterView<?> parent, View view, int position,
				long id) {
			Toast.makeText(MessageRead.this, "����˵�:"+position, Toast.LENGTH_SHORT).show();
		}
	}; 
}
