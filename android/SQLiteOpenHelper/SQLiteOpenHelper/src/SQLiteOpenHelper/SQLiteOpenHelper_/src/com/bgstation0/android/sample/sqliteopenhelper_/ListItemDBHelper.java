package com.bgstation0.android.sample.sqliteopenhelper_;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

// �N���XListItemDBHelper
public class ListItemDBHelper extends SQLiteOpenHelper{	// SQLiteOpenHelper�̔h���N���X.

	// �����o�t�B�[���h�̒�`.
	static final String DB = "list_item.db";	// DB����"list_item.db".
	static final int DB_VERSION = 1;	// DB�o�[�W����1.
	static final String CREATE_TABLE = "create table listitem ( _id integer primary key autoincrement, name string, age integer, address string);";	// CREATE_TABLE��.
	static final String DROP_TABLE = "drop table listitem;";	// DROP_TABLE��.
	
	// �R���X�g���N�^
	public ListItemDBHelper(Context context){
		super(context, DB, null, DB_VERSION);	// �e�N���X�R���X�g���N�^�ɔC����.
	}
	
	// �����o���\�b�h�̒�`.
	// DB�쐬��.
	public void onCreate(SQLiteDatabase db){
		// �e�[�u���쐬�̎��s.
		try{	// try�ň͂�.
			db.execSQL(CREATE_TABLE);	// db.execSQL��CREATE_TABLE�����s.
		}
		catch(Exception ex){	// ��O�L���b�`.
			Log.e("SQLiteOpenHelper_", ex.toString());	// ex.toString��Log�ɏo��.
		}
	}
	
	// DB�o�[�W�����A�b�v�O���[�h��.
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
		// �e�[�u���č쐬.
		db.execSQL(DROP_TABLE);	// ��������h���b�v.
		onCreate(db);	// �č쐬.
	}
}
