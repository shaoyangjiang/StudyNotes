/*
 * Copyright (C) nonobank.com 沪ICP备13003999号
 *                               版权所有：诺诺镑客
 *						        客户热线：4000-646-668
 * Created on 2013-4-8 上午11:07:31 
 */
package com.nonobank.app.adapter;

import java.util.HashMap;
import java.util.List;

import com.nonobank.app.model.R;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageButton;
import android.widget.TextView;

/**
 * 已读消息适配器
 * @author shaoyangjiang
 * Created on 2013-4-8 上午11:07:31
 */
public class MessageReadListAdapter extends BaseAdapter{

	private Context context;
	private List<HashMap<String,Object>> list;
	
	public MessageReadListAdapter(Context context,List<HashMap<String,Object>> list){
		this.context = context;
		this.list = list;
	}
	
	@Override
	public int getCount() {
		return list.size();
	}

	@Override
	public Object getItem(int position) {
		return list.get(position);
	}

	@Override
	public long getItemId(int position) {
		return position;
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		ViewHolder holder;
		if(convertView == null){
			holder = new ViewHolder();
			LayoutInflater mInflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
			convertView = mInflater.inflate(R.layout.message_read_item, null);
			holder.messageNumber = (TextView) convertView.findViewById(R.id.message_number);
			holder.messageTime = (TextView) convertView.findViewById(R.id.message_time);
			holder.messageBody = (TextView) convertView.findViewById(R.id.message_body);
			holder.messageMore = (ImageButton) convertView.findViewById(R.id.message_more);
			convertView.setTag(holder);
		} else{
			holder = (ViewHolder) convertView.getTag();
		}
		
		holder.messageNumber.setText(list.get(position).get("_messageNumber").toString());
		holder.messageTime.setText(list.get(position).get("_messageTime").toString());
		holder.messageBody.setText(list.get(position).get("_messageBody").toString());
		holder.messageMore.setImageResource(R.drawable.next);
		return convertView;
	}

	private class ViewHolder{
		private TextView messageNumber;
		private TextView messageTime;
		private TextView messageBody;
		private ImageButton messageMore;
	}
	
}
