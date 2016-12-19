package com.tiantian.test.database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper {
	private static final int VERSION = 1;

	// ��SQLiteOpenHelper�����б�����øù��캯��
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

	// �ú������ڵ�һ�δ������ݿ�ʱִ�У�ʵ�������ڵ�һ�εõ�SQLiteOpenHelper�����ʱ��Ż�����������
	@Override
	public void onCreate(SQLiteDatabase arg0) {
		System.out.println("create a Database");
		// execSQL��������ִ��SQL���
		// ������
		arg0.execSQL("create table storeTb(_Id INTEGER PRIMARY KEY AUTOINCREMENT, storeName varchar(20))");

	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
		System.out.println("upgrade a Database");
	}

}
