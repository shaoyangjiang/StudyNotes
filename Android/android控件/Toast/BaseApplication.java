package it.neokree.materialtabtest.ui;

import android.app.Application;
import android.content.Context;
import android.database.sqlite.SQLiteDatabase;

import com.example.greendao.DaoMaster;
import com.example.greendao.DaoSession;

import it.neokree.materialtabtest.util.Constants;

/**
 * Created by shaoyangjiang on 2015/11/10.
 */
public class BaseApplication extends Application {
    public static Context context;
    @Override
    public void onCreate() {
        context = this;
    }

}