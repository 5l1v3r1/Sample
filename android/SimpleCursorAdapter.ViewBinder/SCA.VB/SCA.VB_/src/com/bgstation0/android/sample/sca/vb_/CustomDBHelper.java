package com.bgstation0.android.sample.sca.vb_;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

public class CustomDBHelper extends SQLiteOpenHelper {

	// �����o�t�B�[���h�̒�`.
	private static final String DB = "custom.db";	// DB����"custom.db".
	private static final int DB_VERSION = 1;	// DB�o�[�W����1.
	private static final String CREATE_TABLE = "create table custom ( _id integer primary key, name string, age string);";	// CREATE_TABLE��.
	private static final String DROP_TABLE = "drop table custom;";	// DROP_TABLE��.
		
	// �R���X�g���N�^
	public CustomDBHelper(Context context){
		super(context, DB, null, DB_VERSION);	// �e�N���X�R���X�g���N�^�ɔC����.
	}
	
	// DB�쐬��.
	public void onCreate(SQLiteDatabase db){
		// �e�[�u���쐬�̎��s.
		try{	// try�ň͂�.
			db.execSQL(CREATE_TABLE);	// db.execSQL��CREATE_TABLE�����s.
		}
		catch(Exception ex){	// ��O�L���b�`.
			Log.e("SimpleCursorAdapter_", ex.toString());	// ex.toString��Log�ɏo��.
		}
	}

	// DB�o�[�W�����A�b�v�O���[�h��.
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
		// �e�[�u���č쐬.
		db.execSQL(DROP_TABLE);	// ��������h���b�v.
		onCreate(db);	// �č쐬.
	}

}