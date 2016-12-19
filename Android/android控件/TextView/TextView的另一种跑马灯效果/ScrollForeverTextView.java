package com.sigma.sigmacoupons.customview;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.TextView;

/**
 * ����(�����Ч��)��TextView
 * @author com.tiantian
 * @version ����ʱ�䣺2012-10-8 ����11:45:43
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
