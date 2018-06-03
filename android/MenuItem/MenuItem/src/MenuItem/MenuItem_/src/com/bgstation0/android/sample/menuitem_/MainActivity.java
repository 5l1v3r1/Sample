package com.bgstation0.android.sample.menuitem_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // �I�v�V�������j���[���쐬����鎞.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){

    	// ���j���[�̍쐬
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflater��MenuItem���擾��, ���̂܂�inflate�Ŏw�肳�ꂽR.menu.main������menu���쐬.
    	return true;	// true��Ԃ�.
    	
    }
    
    // ���j���[���I�����ꂽ��.
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    
    	// �^�C�g�����g�[�X�g�\��.
    	Toast.makeText(this, item.getTitle().toString(), Toast.LENGTH_LONG).show();	// �I�����ꂽ�A�C�e���̃^�C�g����\��.
    	return true;
    	
    }
    
}