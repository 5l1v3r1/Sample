package com.bgstation0.android.sample.contentprovider_;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.ContentValues;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	ContentResolver mContentResolver = null;	// mContentResolver��null�ŏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ContentResolver�̎擾.
        mContentResolver = getContentResolver();	// mContentResolver���擾.
        
        // query���Ăяo��.
        Uri uri = Uri.parse("content://com.bgstation0.android.sample.customcontentprovider/");	// "content://com.bgstation0.android.sample.customcontentprovider/"���p�[�X����, uri�ɂ���.
        Cursor cursor1 = mContentResolver.query(uri, null, null, null, null);	// mContentResolver.query��cursor1���擾.
        if (cursor1 == null){	// null�Ȃ�.
        	Toast.makeText(this, "cursor1 == null", Toast.LENGTH_LONG).show();	// "cursor1 == null"��\��.
        }
        
        // insert���Ăяo��.
        ContentValues values = new ContentValues();	// values�̍쐬.
        values.put("key", "value");	// �L�[��"key", �l��"value".
        Uri res1 = mContentResolver.insert(uri, values);	// mContentResolver.insert��values��}��.
        if (res1 == null){	// null�Ȃ�.
        	Toast.makeText(this, "res1 == null", Toast.LENGTH_LONG).show();	// "res1 == null"��\��.
        }
        
        // update���Ăяo��.
        ContentValues values2 = new ContentValues();	// values�̍쐬.
        values.put("key", "newvalue");	// �L�[��"key", �l��"newvalue".
        int ret1 = mContentResolver.update(uri, values2, "", null);	// mContentResolver.update��values�ɍX�V.
        if (ret1 == 1){	// 1�Ȃ�.
        	Toast.makeText(this, "ret1 == 1", Toast.LENGTH_LONG).show();	// "ret1 == 1"��\��.
        }
        
        // delete���Ăяo��.
        int count1 = mContentResolver.delete(uri, "", null);	// mContentResolver.delete�ō폜.
        if (count1 == -1){	// -1�Ȃ�.
        	Toast.makeText(this, "count1 == -1", Toast.LENGTH_LONG).show();	// "count1 == -1"��\��.
        }
        
    }
    
}