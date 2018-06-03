package com.bgstation0.android.sample.sv.oqtl_;

import android.app.ActionBar;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.SearchView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements SearchView.OnQueryTextListener{

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null�ɏ�����.
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;	// mContext��this���Z�b�g.
    }
    
    // ���j���[���쐬���ꂽ��.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// ���j���[�̍쐬
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflater��MenuItem���擾��, ���̂܂�inflate�Ŏw�肳�ꂽR.menu.main������menu���쐬.
    	ActionBar actionBar = getActionBar();	// getActionBar��actionBar���擾.
    	actionBar.setDisplayShowTitleEnabled(false);	// actionBar.setDisplayShowTitleEnabled��false�ɂ��ă^�C�g�����\��.
    	actionBar.setDisplayShowHomeEnabled(false);	// actionBar.setDisplayShowHomeEnabled��false�ɂ��ăA�C�R������\��.
    	
    	// SearchView�̎擾.
    	MenuItem menuItemSearch = menu.findItem(R.id.menu_item_searchview);	// menuItemSearch�̎擾.
    	SearchView searchView = (SearchView)menuItemSearch.getActionView();	// searchView�̎擾.
    	searchView.setOnQueryTextListener(this);	// this���Z�b�g.
    	return true;
    	
    }
    
    // �N�G���e�L�X�g���ύX���ꂽ��.
	@Override
	public boolean onQueryTextChange(String newText){
		
		// �e�L�X�g���ύX���ꂽ��, textview1��ύX.
		TextView textview1 = (TextView)((MainActivity)mContext).findViewById(R.id.textview1);	// textview1���擾.
		textview1.setText(newText);	// textview1��newText���Z�b�g.
		return false;
		
	}
	
	// �N�G���e�L�X�g�����肵����.
	@Override
	public boolean onQueryTextSubmit(String query){
		
		// ����ς݃N�G���e�L�X�g��\��.
		Toast.makeText(mContext, query, Toast.LENGTH_LONG).show();	// query��\��.
		return false;
		
	}
    
}