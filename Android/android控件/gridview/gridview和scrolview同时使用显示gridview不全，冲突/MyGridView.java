/*
 * Copyright (C) nonobank.com ��ICP��13003999��
 *                               ��Ȩ���У�ŵŵ����
 *						        �ͻ����ߣ�4000-646-668
 * Created on 2013-3-28 ����11:31:50 
 */
package com.nonobank.app.util;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.GridView;

/**
 * Document Instruction
 * @author shaoyangjiang
 * Created on 2013-3-28 ����11:31:50
 */
public class MyGridView extends GridView {

	   public MyGridView(Context context, AttributeSet attrs) { 
	        super(context, attrs); 
	    } 

	    public MyGridView(Context context) { 
	        super(context); 
	    } 

	    public MyGridView(Context context, AttributeSet attrs, int defStyle) { 
	        super(context, attrs, defStyle); 
	    } 

	    @Override 
	    public void onMeasure(int widthMeasureSpec, int heightMeasureSpec) { 

	        int expandSpec = MeasureSpec.makeMeasureSpec( 
	                Integer.MAX_VALUE >> 2, MeasureSpec.AT_MOST); 
	        super.onMeasure(widthMeasureSpec, expandSpec); 
	    } 
	    
}
