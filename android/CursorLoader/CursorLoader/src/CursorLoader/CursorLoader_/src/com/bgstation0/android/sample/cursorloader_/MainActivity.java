package com.bgstation0.android.sample.cursorloader_;

import android.app.Activity;
import android.app.LoaderManager;
import android.content.ContentValues;
import android.content.CursorLoader;
import android.content.Loader;
import android.database.Cursor;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;

public class MainActivity extends Activity implements LoaderManager.LoaderCallbacks<Cursor>{

	// �����o�t�B�[���h�̒�`.
	CustomCursorAdapter mAdapter = null;	// mAdapter��null���Z�b�g.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �A�C�e���̏���.
        ContentValues values1 = new ContentValues();	// values1�̐���.
        values1.put("text1", "AAA");	// text1�̒ǉ�.
        values1.put("text2", "AAAAA");	// text2�̒ǉ�.
        getContentResolver().insert(CustomDBHelper.CONTENT_URI, values1);	// values1�̒ǉ�.
        ContentValues values2 = new ContentValues();	// values2�̐���.
        values2.put("text1", "BBB");	// text1�̒ǉ�.
        values2.put("text2", "BBBBB");	// text2�̒ǉ�.
        getContentResolver().insert(CustomDBHelper.CONTENT_URI, values2);	// values2�̒ǉ�.
        ContentValues values3 = new ContentValues();	// values3�̐���.
        values3.put("text1", "CCC");	// text1�̒ǉ�.
        values3.put("text2", "CCCCC");	// text2�̒ǉ�.
        getContentResolver().insert(CustomDBHelper.CONTENT_URI, values3);	// values3�̒ǉ�.
        
        // ListView�̎擾.
        ListView listView1 = (ListView)findViewById(R.id.listview1);	// listView1�̎擾.
        
        // Adapter�̐���.
        mAdapter = new CustomCursorAdapter(this, null, true);	// mAdapter�̐���.
        
        // �A�_�v�^�̃Z�b�g.
        listView1.setAdapter(mAdapter);	// mAdapter�̃Z�b�g.
        
        // ���[�_�[�̏�����.
        getLoaderManager().initLoader(0, null, this);	// initLoader�ŊJ�n.
        
    }
    
    // ���j���[���쐬���ꂽ��.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// ���j���[�̍쐬
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflater��MenuItem���擾��, ���̂܂�inflate�Ŏw�肳�ꂽR.menu.main������menu���쐬.
    	return true;
    	
    }
    
    // ���j���[���I�����ꂽ��.
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    	
    	// �ǂ̃��j���[���I�����ꂽ��.
    	switch (item.getItemId()){	// �A�C�e��ID���ƂɐU�蕪��.
    	
    		// Insert
    		case R.id.menu_item_insert:
    	
    			// DDD�̒ǉ�.
    			ContentValues values4 = new ContentValues();	// values4�̐���.
    	        values4.put("text1", "DDD");	// text1�̒ǉ�.
    	        values4.put("text2", "DDDDD");	// text2�̒ǉ�.
    	        getContentResolver().insert(CustomDBHelper.CONTENT_URI, values4);	// values4�̒ǉ�.
    	        getLoaderManager().restartLoader(0, null, this);	// ���X�^�[�g.
    			break;
    			
    	}
    	return super.onOptionsItemSelected(item);	// �e�N���X���菈��
    	
    }
    
    // ���[�_�[����.
    @Override
    public Loader<Cursor> onCreateLoader(int id, Bundle bundle) {

    	// CursorLoader����.
        return new CursorLoader(this, CustomDBHelper.CONTENT_URI, null, null, null, null);	// CursorLoader�𐶐����ĕԂ�.
        
    }

    // ���[�_�[�I��.
    @Override
    public void onLoadFinished(Loader<Cursor> loader, Cursor cursor) {
    	
    	// ��ʂ̍X�V.
    	mAdapter.swapCursor(cursor);	// �X���b�v.
    	mAdapter.notifyDataSetChanged();	// �X�V.
    	
    }

    // ���[�_�[���Z�b�g.
    @Override
    public void onLoaderReset(Loader<Cursor> loader) {
        
    	// null�Ɠ���ւ�.
    	mAdapter.swapCursor(null);	// null���Z�b�g.
    	
    }

}