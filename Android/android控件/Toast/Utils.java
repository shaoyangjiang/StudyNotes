package it.neokree.materialtabtest.util;

/**
 * Created by shaoyangjiang on 2015/11/24.
 */

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.support.design.widget.Snackbar;
import android.view.View;
import android.widget.Toast;

import it.neokree.materialtabtest.ui.BaseApplication;

/**
 * 常用的工具类集合！
 */
public class Utils {
    /**
     * 判断SD卡是否存在！
     *
     * @return
     */
    public static boolean checkSD() {
        return android.os.Environment.getExternalStorageState().equals(
                android.os.Environment.MEDIA_MOUNTED);
    }

    /**
     * 判断当前用户手机有没有网络
     * (wifi and traffic)
     * @param context
     * @return
     */
    public static boolean checkNet(Context context) {
        boolean wifiConnected = isWIFIConnected(context);
        boolean mobileConnected = isMOBILEConnected(context);
        if (wifiConnected == false && mobileConnected == false) {
            // 去提示用户没有网络
            return false;
        }
        return true;

    }

    /**显示短时间Toast
     * @param
     * @return void
     * @throws
     * @Description: 显示短时间Toast
     */
    public static void toastShort(CharSequence sequence) {
        Toast.makeText(BaseApplication.context, sequence, Toast.LENGTH_SHORT).show();
    }

    /**显示长时间Toast
     * @param
     * @return void
     * @throws
     * @Description: 显示长时间Toast
     */
    public static void toastLong(CharSequence sequence) {
        Toast.makeText(BaseApplication.context, sequence, Toast.LENGTH_SHORT).show();
    }


    /**
     * 显示snackbar
     * @param view 在那个控件下显示
     * @param sequence
     */
    public static void snackbar(View view,CharSequence sequence){
        final Snackbar snackbar = Snackbar.make(view,sequence,Snackbar.LENGTH_INDEFINITE);
        snackbar.show();
        snackbar.setAction("知道了", new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                snackbar.dismiss();
            }
        });
    }
    /**
     * 判断手机是否使用wifi连接
     *
     * @param context
     * @return
     */
    public static boolean isWIFIConnected(Context context) {
        ConnectivityManager manager = (ConnectivityManager) context
                .getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo networkInfo = manager
                .getNetworkInfo(ConnectivityManager.TYPE_WIFI);
        if (networkInfo != null && networkInfo.isConnected()) {
            return true;
        }
        return false;
    }

    /**
     * 判断手机是否使用流量连接 大数据下提示用户使用wifi节省流量！
     *
     * @param context
     * @return
     */
    public static boolean isMOBILEConnected(Context context) {
        ConnectivityManager manager = (ConnectivityManager) context
                .getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo networkInfo = manager
                .getNetworkInfo(ConnectivityManager.TYPE_MOBILE);
        if (networkInfo != null && networkInfo.isConnected()) {
            return true;
        }
        return false;

    }

}
