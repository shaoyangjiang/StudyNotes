package com.tiantian.test.database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper {
	private static final int VERSION = 1;

	// 在SQLiteOpenHelper子类中必须调用该构造函数
	public DatabaseHelper(Context context, String name, CursorFactory factory,
			int version) {
		super(context, name, factory, version);
	}

	public DatabaseHelper(Context context, String name, int version) {
		this(context, name, null, version);
	}

	public DatabaseHelper(Context context, String name) {
		this(context, name, VERSION);
	}

	// 该函数是在第一次创建数据库时执行，实际上是在第一次得到SQLiteOpenHelper对象的时候才会调用这个方法
	@Override
	public void onCreate(SQLiteDatabase arg0) {
		System.out.println("create a Database");
		// execSQL函数用于执行SQL语句
		// 创建表
		arg0.execSQL("create table storeTb(_Id INTEGER PRIMARY KEY AUTOINCREMENT, storeName varchar(20))");

	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
		System.out.println("upgrade a Database");
	}

}
