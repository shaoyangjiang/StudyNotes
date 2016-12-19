package com.nonobank.app.adapter;

import com.nonobank.app.model.R;
import android.app.Dialog;
import android.content.Context;
import android.os.Bundle;



/**
 * @author com.shaoyangjiang
 * @version 创建时间：2012-10-14 下午3:25:56
 */
public class LoadingDialog extends Dialog {

    public LoadingDialog(Context context) {
        super(context, R.style.LoadingDialogStyle);
        //setOwnerActivity((Activity) context);// 设置dialog全屏显示
        this.setCanceledOnTouchOutside(false);
    }

    private LoadingDialog(Context context, int theme) {
        super(context, theme);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.loading_dialog);
    }

}
