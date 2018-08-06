package com.bgstation0.android.sample.sca.vb_;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.TextView;

public class MainActivity extends Activity implements SimpleCursorAdapter.ViewBinder{

	// �����o�t�B�[���h�̒�`.
	public CustomDBHelper mHlpr = null;	// CustomDBHelper�I�u�W�F�N�gmHlpr��null�ɂ��Ă���.
	public SQLiteDatabase mSqlite = null;	// SQLiteDatabase�I�u�W�F�N�gmSqlite��null�ɂ��Ă���.
	public SimpleCursorAdapter mAdapter = null;	// SimpleCursorAdapter�I�u�W�F�N�gmAdapter��null�ɂ��Ă���.
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
        				values1.put("age", "20");	// �L�[��"age", �l��"20".
        				long i = mSqlite.insert("custom", null, values1);	// �}��.
        				ContentValues values2 = new ContentValues();	// values2�̐���.
        				values2.put("name", "Jiro");	// �L�[��"name", �l��"Jiro".
        				values2.put("age", "18");	// �L�[��"age", �l��"18".
        				long i2 = mSqlite.insert("custom", null, values2);	// �}��.
        				ContentValues values3 = new ContentValues();	// values3�̐���.
        				values3.put("name", "Saburo");	// �L�[��"name", �l��"Saburo".
        				values3.put("age", "16");	// �L�[��"age", �l��"16".
        				long i3 = mSqlite.insert("custom", null, values3);	// �}��.
        				// �I��.
        				String[] projection = new String[]{
        						"_id", // ID.
        						"name",	// ���O.
        						"age" // �N��.
        				};
        				mCursor = mSqlite.query("custom", projection, null, null, null, null, "age desc");	// �N�G�����ʂ�mCursor�Ɋi�[.
        				mAdapter = new SimpleCursorAdapter(this, R.layout.list_item, mCursor, new String[]{"name", "age"}, new int[]{R.id.list_item_name, R.id.list_item_age}, 0);	// SimpleCursorAdapter�I�u�W�F�N�gmAdapter�̐���.
        				mAdapter.setViewBinder(this);	// this���Z�b�g.
        				listView1.setAdapter(mAdapter);	// listView1��mAdapter���Z�b�g.
        			}
        		}
        	}	
        }
        catch (Exception ex){	// ��O.
        	Log.e("SimpleCursorAdapter_", ex.toString());	// ex.toString��Log�ɏo��.
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
    
    @Override
	public boolean setViewValue(View view, Cursor cursor, int columnIndex) {
		// TODO Auto-generated method stub
		// �J������1�Ԗڂ��ǂ���.(_id��0�Ԗ�.)
		if (columnIndex == 1){	// 1�Ԗ�.(name)
			int color = getResources().getColor(android.R.color.holo_red_light);	// �Ԃ�color�擾.
			((TextView)view).setTextColor(color);	//view�ɃZ�b�g.
		}
		else{	// 1�ԖڈȊO.(age)
			int color = getResources().getColor(android.R.color.holo_blue_light);	// ��color�擾.
			((TextView)view).setTextColor(color);	//view�ɃZ�b�g.
		}
		return false;
	}
    
}