package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	final int MENU_TYPE_A = 0;	// �萔MENU_TYPE_A��0�Ƃ���.
	final int MENU_TYPE_B = 1;	// �萔MENU_TYPE_B��1�Ƃ���.
	int menuType = MENU_TYPE_A;	// menuType��MENU_TYPE_A�ŏ�����.
	
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
    	
    	// �ŏ���"Change"��"A1"�`"A3"�����\���ł��Ƃ͔�\��.
    	MenuItem itemB1 = menu.findItem(R.id.menu_item_b1);	// menu.findItem��itemB1���擾.
    	itemB1.setVisible(false);	// itemB1.setVisible�Ŕ�\���ɂ���.
    	MenuItem itemB2 = menu.findItem(R.id.menu_item_b2);	// menu.findItem��itemB2���擾.
    	itemB2.setVisible(false);	// itemB2.setVisible�Ŕ�\���ɂ���.
    	MenuItem itemB3 = menu.findItem(R.id.menu_item_b3);	// menu.findItem��itemB3���擾.
    	itemB3.setVisible(false);	// itemB3.setVisible�Ŕ�\���ɂ���.
    	
    	// true��Ԃ�.
    	return true;	// true��Ԃ�.
    	
    }
    
    // ���j���[�̕\���̂��߂̏������s��ꂽ��.
    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
    
    	// menuType�ɂ���ĕ\����؂�ւ�.
    	if (menuType == MENU_TYPE_A){	// MENU_TYPE_A�Ȃ�.
    		MenuItem itemB1 = menu.findItem(R.id.menu_item_b1);	// menu.findItem��itemB1���擾.
        	itemB1.setVisible(false);	// itemB1.setVisible�Ŕ�\���ɂ���.
        	MenuItem itemB2 = menu.findItem(R.id.menu_item_b2);	// menu.findItem��itemB2���擾.
        	itemB2.setVisible(false);	// itemB2.setVisible�Ŕ�\���ɂ���.
        	MenuItem itemB3 = menu.findItem(R.id.menu_item_b3);	// menu.findItem��itemB3���擾.
        	itemB3.setVisible(false);	// itemB3.setVisible�Ŕ�\���ɂ���.
    		MenuItem itemA1 = menu.findItem(R.id.menu_item_a1);	// menu.findItem��itemA1���擾.
        	itemA1.setVisible(true);	// itemA1.setVisible�ŕ\���ɂ���.
        	MenuItem itemA2 = menu.findItem(R.id.menu_item_a2);	// menu.findItem��itemA2���擾.
        	itemA2.setVisible(true);	// itemA2.setVisible�ŕ\���ɂ���.
        	MenuItem itemA3 = menu.findItem(R.id.menu_item_a3);	// menu.findItem��itemA3���擾.
        	itemA3.setVisible(true);	// itemA3.setVisible�ŕ\���ɂ���.
    	}
    	else{	// MENU_TYPE_B�Ȃ�.
    		MenuItem itemA1 = menu.findItem(R.id.menu_item_a1);	// menu.findItem��itemA1���擾.
        	itemA1.setVisible(false);	// itemA1.setVisible�Ŕ�\���ɂ���.
        	MenuItem itemA2 = menu.findItem(R.id.menu_item_a2);	// menu.findItem��itemA2���擾.
        	itemA2.setVisible(false);	// itemA2.setVisible�Ŕ�\���ɂ���.
        	MenuItem itemA3 = menu.findItem(R.id.menu_item_a3);	// menu.findItem��itemA3���擾.
        	itemA3.setVisible(false);	// itemA3.setVisible�Ŕ�\���ɂ���.
        	MenuItem itemB1 = menu.findItem(R.id.menu_item_b1);	// menu.findItem��itemB1���擾.
        	itemB1.setVisible(true);	// itemB1.setVisible�ŕ\���ɂ���.
        	MenuItem itemB2 = menu.findItem(R.id.menu_item_b2);	// menu.findItem��itemB2���擾.
        	itemB2.setVisible(true);	// itemB2.setVisible�ŕ\���ɂ���.
        	MenuItem itemB3 = menu.findItem(R.id.menu_item_b3);	// menu.findItem��itemB3���擾.
        	itemB3.setVisible(true);	// itemB3.setVisible�ŕ\���ɂ���.
    	}
    	
    	// true��Ԃ�.
    	return true;	// true��Ԃ�.
    	
    }
    
    // ���j���[�A�C�e�����I�����ꂽ��.
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
    	
    	// item��menu_change�Ȃ�, menuType��؂�ւ���.
    	if (item.getItemId() == R.id.menu_change){	// R.id.menu_change�Ȃ�.
	    	if (menuType == MENU_TYPE_A){	// MENU_TYPE_A�Ȃ�.
	    		menuType = MENU_TYPE_B;	// menuType��MENU_TYPE_B����.
	    	}
	    	else{	// MENU_TYPE_B�Ȃ�.
	    		menuType = MENU_TYPE_A;	// menuType��MENU_TYPE_A����.
	    	}
    	}
    	
    	// true��Ԃ�.
    	return true;	// true��Ԃ�.
    	
    }
    
}