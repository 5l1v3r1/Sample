package com.bgstation0.android.sample.activity_;

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
    	
    	// �ǂ̃��j���[���I�����ꂽ��.
    	switch (item.getItemId()){	// �A�C�e��ID���ƂɐU�蕪��.
    	
    		// Menu1
    		case R.id.menu_menu1:
    			
    			// "Menu1"�ƕ\��.
    			Toast.makeText(this, "Menu1", Toast.LENGTH_SHORT).show();	// Toast��"Menu1"��\��.
    			break;
    			
    		// Menu2
    		case R.id.menu_menu2:
    			
    			// "Menu2"�ƕ\��.
    			Toast.makeText(this, "Menu2", Toast.LENGTH_SHORT).show();	// Toast��"Menu2"��\��.
    			break;
    			
    		// Menu3
    		case R.id.menu_menu3:
    			
    			// "Menu3"�ƕ\��.
    			Toast.makeText(this, "Menu3", Toast.LENGTH_SHORT).show();	// Toast��"Menu3"��\��.
    			break;
    			
    	}
    	return super.onOptionsItemSelected(item);	// �e�N���X���菈��
    }
}
