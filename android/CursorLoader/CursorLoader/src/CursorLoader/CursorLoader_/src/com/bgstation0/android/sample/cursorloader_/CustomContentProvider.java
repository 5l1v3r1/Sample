package com.bgstation0.android.sample.cursorloader_;

import android.content.ContentProvider;
import android.content.ContentUris;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;

public class CustomContentProvider extends ContentProvider {

	// �����o�t�B�[���h�̒�`.
	private CustomDBHelper mHlpr = null;	// mHlpr��null���Z�b�g.
	
	@Override
	public boolean onCreate() {
		// TODO Auto-generated method stub
		mHlpr = new CustomDBHelper(getContext());	// mHlpr�̍쐬.
		return true;	// true.
	}

	@Override
	public Cursor query(Uri uri, String[] projection, String selection,
			String[] selectionArgs, String sortOrder) {
		// TODO Auto-generated method stub
		SQLiteDatabase sqlite = mHlpr.getReadableDatabase();	// sqlite��ǂݍ��ݐ�p�Ŏ擾.
		Cursor c = sqlite.query(CustomDBHelper.TABLE_NAME, null, null, null, null, null, null);	// query�Ŗ₢���킹.
		return c;	// c��Ԃ�.
	}

	@Override
	public String getType(Uri uri) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Uri insert(Uri uri, ContentValues values) {
		// TODO Auto-generated method stub
		SQLiteDatabase sqlite = mHlpr.getWritableDatabase();	// �������ݗp�Ŏ擾.
		long id = sqlite.insert(CustomDBHelper.TABLE_NAME, null, values);	// insert�ő}��.
		Uri newUri = ContentUris.withAppendedId(CustomDBHelper.CONTENT_URI, id);	// newUri�擾.
		return newUri;	// newUri��Ԃ�.
	}

	@Override
	public int delete(Uri uri, String selection, String[] selectionArgs) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int update(Uri uri, ContentValues values, String selection,
			String[] selectionArgs) {
		// TODO Auto-generated method stub
		return 0;
	}

}