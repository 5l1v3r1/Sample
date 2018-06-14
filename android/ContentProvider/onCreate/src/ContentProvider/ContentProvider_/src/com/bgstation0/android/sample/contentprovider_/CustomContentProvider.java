package com.bgstation0.android.sample.contentprovider_;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.net.Uri;
import android.util.Log;
import android.widget.Toast;

public class CustomContentProvider extends ContentProvider {
	
	// �����X�^�e�B�b�N�N���X�Ƃ���CustomDBHelper���`.
	private static class CustomDBHelper extends SQLiteOpenHelper{
		
		// �����o�t�B�[���h�̒�`.
		private static final String CREATE_TABLE = "create table custom ( _id integer primary key, name string, content string);";	// CREATE_TABLE��.
		private static final String DROP_TABLE = "drop table custom;";	// DROP_TABLE��.
		
		// �R���X�g���N�^
		CustomDBHelper(Context context){
			super(context, "custom.db", null, 1);	// �e�R���X�g���N�^��context, DB��"custom.db", DB�o�[�W����1�Ȃǂ�n��.
		}
		
		// DB�̍쐬��.
		public void onCreate(SQLiteDatabase db){
			db.execSQL(CREATE_TABLE);	// db.execSQL�Ńe�[�u���쐬.
		}
		
		// �A�b�v�O���[�h��.
		@Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
            db.execSQL(DROP_TABLE);	// db.execSQL�Ńe�[�u���폜.
            onCreate(db);	// onCreate�ōĂуe�[�u���쐬.
        }
		
	}
	
	// �����o�̒�`.
	private CustomDBHelper customDBHelper;	// DB�w���p�[�̃C���X�^���X.
	
	// �쐬���ꂽ��.
	@Override
	public boolean onCreate() {
		// TODO Auto-generated method stub
		// �\��.
		Log.d("CustomContentProvider", "onCreate");	// Log.d��"onCreate"��\��.
		// DB�w���p�[�̍쐬.
		customDBHelper = new CustomDBHelper(getContext());	// customDBHelper�𐶐�.
		Log.d("CustomContentProvider", "customDBHelper.toString() = " + customDBHelper.toString());	// customDBHelper.toString()��\��.
		//return false;
		return true;	// true��Ԃ�.
	}

	// �₢���킹��.
	@Override
	public Cursor query(Uri uri, String[] projection, String selection,
			String[] selectionArgs, String sortOrder) {
		// TODO Auto-generated method stub
		// �\��.
		Log.d("CustomContentProvider", "query");	// Log.d��"query"��\��.
		return null;
	}

	// �^�̎擾��.
	@Override
	public String getType(Uri uri) {
		// TODO Auto-generated method stub
		// �\��.
		Log.d("CustomContentProvider", "getType");	// Log.d��"getType"��\��.
		return null;
	}

	// �}�����鎞.
	@Override
	public Uri insert(Uri uri, ContentValues values) {
		// TODO Auto-generated method stub
		// �\��.
		Log.d("CustomContentProvider", "insert");	// Log.d��"insert"��\��.
		return null;
	}

	// �X�V���鎞.
	@Override
	public int update(Uri uri, ContentValues values, String selection,
			String[] selectionArgs) {
		// TODO Auto-generated method stub
		// �\��.
		Log.d("CustomContentProvider", "update");	// Log.d��"update"��\��.
		return 1;	// 1��Ԃ�.
	}
	
	// �폜���鎞.
	@Override
	public int delete(Uri uri, String selection, String[] selectionArgs) {
		// TODO Auto-generated method stub
		// �\��.
		Log.d("CustomContentProvider", "delete");	// Log.d��"delete"��\��.
		//return 0;
		return -1;	// -1��Ԃ�.
	}

}