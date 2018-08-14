package com.bgstation0.android.sample.cursorloader_;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import android.net.Uri;
import android.util.Log;

public class CustomDBHelper extends SQLiteOpenHelper {

	// �����o�t�B�[���h�̒�`.
	public static final String AUTHORITY = "com.bgstation0.android.sample.cursorloader_.customcontentprovider";	// AUTHORITY�̒�`.
	public static final Uri CONTENT_URI = Uri.parse("content://" + AUTHORITY);	// CONTENT_URI�̒�`.
	public static final String DB_NAME = "custom.db";	// DATABASE_NAME�̒�`.
	public static final int DB_VERSION = 1;	// DB_VERSION�̒�`.
	public static final String TABLE_NAME = "custom_table";	// TABLE_NAME�̒�`.
	public static final String CREATE_TABLE = "create table " + TABLE_NAME + " ( _id integer primary key, text1 string, text2 string);";	// CREATE_TABLE���̒�`.
	public static final String DROP_TABLE = "drop table " + TABLE_NAME + ";";	// DROP_TABLE���̒�`.
	
	// �R���X�g���N�^
	public CustomDBHelper(Context context){
		super(context, DB_NAME, null, DB_VERSION);	// �e�R���X�g���N�^�ɓn��.
	}
	
	// �����o���\�b�h�̒�`.
	// DB�쐬��.
	public void onCreate(SQLiteDatabase db){
		// �e�[�u���쐬�̎��s.
		try{	// try�ň͂�.
			db.execSQL(CREATE_TABLE);	// db.execSQL��CREATE_TABLE�����s.
		}
		catch(Exception ex){	// ��O�L���b�`.
			Log.e("CustomLoader_", ex.toString());	// ex.toString��Log�ɏo��.
		}
	}
	
	// DB�o�[�W�����A�b�v�O���[�h��.
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
		// �e�[�u���č쐬.
		db.execSQL(DROP_TABLE);	// ��������h���b�v.
		onCreate(db);	// �č쐬.
	}
	
}