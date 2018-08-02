package com.bgstation0.android.sample.cursoradapter_;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	public CustomDBHelper mHlpr = null;	// CustomDBHelper�I�u�W�F�N�gmHlpr��null�ɂ��Ă���.
	public SQLiteDatabase mSqlite = null;	// SQLiteDatabase�I�u�W�F�N�gmSqlite��null�ɂ��Ă���.
	public CustomCursorAdapter mAdapter = null;	// CustomCursorAdapter�I�u�W�F�N�gmAdapter��null�ɂ��Ă���.
	public Cursor mCursor = null;	// Cursor�I�u�W�F�N�gmCursor��null�ɂ��Ă���.
	
	// Activity���������ꂽ�Ƃ�.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ListView�̎擾.
        ListView listView1 = (ListView)findViewById(R.id.listview1);	// listView1���擾.
        
        // DB�ւ̍s�̑}��.
        mCursor = null;	// mCursor��null���Z�b�g.
        try{
        	if (mHlpr == null){	// mHlpr��null�Ȃ�.
        		mHlpr = new CustomDBHelper(getApplicationContext());	// mHlpr�쐬.
        		if (mSqlite == null){	// mSqlite��null�Ȃ�.
        			mSqlite = mHlpr.getWritableDatabase();	// mSqlite�擾.
        			if (mSqlite != null){	// mSqlite���擾�ł����.
        				// �}��.
        				ContentValues values1 = new ContentValues();	// values1�̐���.
        				values1.put("name", "Taro");	// �L�[��"name", �l��"Taro".
        				values1.put("age", 20);	// �L�[��"age", �l��20.
        				long i = mSqlite.insert("custom", null, values1);	// �}��.
        				ContentValues values2 = new ContentValues();	// values2�̐���.
        				values2.put("name", "Jiro");	// �L�[��"name", �l��"Jiro".
        				values2.put("age", 18);	// �L�[��"age", �l��18.
        				long i2 = mSqlite.insert("custom", null, values2);	// �}��.
        				ContentValues values3 = new ContentValues();	// values3�̐���.
        				values3.put("name", "Saburo");	// �L�[��"name", �l��"Saburo".
        				values3.put("age", 16);	// �L�[��"age", �l��16.
        				long i3 = mSqlite.insert("custom", null, values3);	// �}��.
        				// �I��.
        				String[] projection = new String[]{
        						"_id", // ID.
        						"name",	// ���O.
        						"age" // �N��.
        				};
        				mCursor = mSqlite.query("custom", projection, null, null, null, null, "age desc");	// �N�G�����ʂ�mCursor�Ɋi�[.
        				mAdapter = new CustomCursorAdapter(this, mCursor, true);	// mAdapter�𐶐�.
        				listView1.setAdapter(mAdapter);	// listView1��mAdapter���Z�b�g.
        			}
        		}
        	}
        }
        catch (Exception ex){	// ��O.
        	Log.e("CursorAdapter", ex.toString());	// ex.toString��Log�ɏo��.
        }
        finally{	// �K�{����
        	if (mSqlite != null){	// mSqlite�������.
        		mSqlite.close();	// ����.
        		mSqlite = null;	// null���Z�b�g.
        	}
        	if (mHlpr != null){	// mHlpr�������.
        		mHlpr.close();	// ����.
        		mHlpr = null;	// null���Z�b�g.
        	}
        }
        
    }
    
    // Activity���j�����ꂽ�Ƃ�.
    protected void onDestroy() {	// onDestroy�̒�`
    	
    	// �e�N���X�̏���
    	super.onDestroy();	// super.onDestroy�Őe�N���X�̊��菈��.
    	
    	// �J�[�\�������.
    	if (mCursor != null){	// mCursor�������.
    		mCursor.close();	// ����.
    		mCursor = null;	// null���Z�b�g.
    	}
    	
    }
    
}