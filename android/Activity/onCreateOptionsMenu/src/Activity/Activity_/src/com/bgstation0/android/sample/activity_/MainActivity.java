package com.bgstation0.android.sample.activity_;

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
    
    // �I�v�V�������j���[���쐬����鎞.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// ���j���[�A�C�e���̒ǉ�.
    	menu.add("Menu1");	// menu.add��"Menu1"��ǉ�.
    	menu.add("Menu2");	// menu.add��"Menu2"��ǉ�.
    	
    	// �e�N���X�̏���.
    	return super.onCreateOptionsMenu(menu);	// super.onCreateOptionsMenu�Őe�N���X�̊��菈��.
    	
    }
}
