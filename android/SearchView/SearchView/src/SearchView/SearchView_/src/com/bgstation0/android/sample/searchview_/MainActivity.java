package com.bgstation0.android.sample.searchview_;

import android.app.ActionBar;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // ���j���[���쐬���ꂽ��.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// ���j���[�̍쐬
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflater��MenuItem���擾��, ���̂܂�inflate�Ŏw�肳�ꂽR.menu.main������menu���쐬.
    	ActionBar actionBar = getActionBar();	// getActionBar��actionBar���擾.
    	actionBar.setDisplayShowTitleEnabled(false);	// actionBar.setDisplayShowTitleEnabled��false�ɂ��ă^�C�g�����\��.
    	actionBar.setDisplayShowHomeEnabled(false);	// actionBar.setDisplayShowHomeEnabled��false�ɂ��ăA�C�R������\��.
    	return true;	// true��Ԃ�.
    	
    }
    
}