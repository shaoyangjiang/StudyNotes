/*
 * Copyright (C) nonobank.com 沪ICP备13003999号
 *                               版权所有：诺诺镑客
 *						        客户热线：4000-646-668
 * Created on 2013-4-1 下午3:16:11 
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
 * Created on 2013-4-1 下午3:16:11
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
	 * 这里以后要从服务器读数据
	 */
	private void showListView(){
		HashMap<String, Object> map = new HashMap<String, Object>();
		
		map.put("_messageNumber", "123456");
		map.put("_messageTime", "上午9点10分");
		map.put("_messageBody", "诺诺镑客的精英们，大家早上好");
		messageReadList.add(map);
		
		map = new HashMap<String, Object>();
		map.put("_messageNumber", "23454523");
		map.put("_messageTime", "下午9点10分");
		map.put("_messageBody", "好，很好，非常好");
		messageReadList.add(map);
		
		map = new HashMap<String, Object>();
		map.put("_messageNumber", "123456");
		map.put("_messageTime", "上午11点12分");
		map.put("_messageBody", "要考试了，纳尼");
		messageReadList.add(map);
	}
	
	/*
	 * 对每个已读信息item进行监听
	 */
	private OnItemClickListener MessageReadItemClickListener = new OnItemClickListener() {

		@Override
		public void onItemClick(AdapterView<?> parent, View view, int position,
				long id) {
			Toast.makeText(MessageRead.this, "点击了第:"+position, Toast.LENGTH_SHORT).show();
		}
	}; 
}
