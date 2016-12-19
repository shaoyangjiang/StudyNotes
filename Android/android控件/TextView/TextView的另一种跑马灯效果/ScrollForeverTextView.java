package com.sigma.sigmacoupons.customview;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.TextView;

/**
 * 滚动(跑马灯效果)的TextView
 * @author com.tiantian
 * @version 创建时间：2012-10-8 上午11:45:43
 */
public class ScrollForeverTextView extends TextView {  
	  
    public ScrollForeverTextView(Context context) {  
        super(context);  
    }  
  
    public ScrollForeverTextView(Context context, AttributeSet attrs) {  
        super(context, attrs);  
    }  
  
    public ScrollForeverTextView(Context context, AttributeSet attrs,  
            int defStyle) {  
        super(context, attrs, defStyle);  
    }  
  
    @Override  
    public boolean isFocused() {  
        return true;  
    }  
  
}  
