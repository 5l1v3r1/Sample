package com.bgstation0.android.sample.menuitem_;

import android.app.ActionBar;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Toast;

public class MainActivity extends Activity {

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
    	
    	// �A�N�V�����r���[�̎擾.
    	MenuItem menuItemSearch = menu.findItem(R.id.menu_item_search_layout);	// menuItemSearch�̎擾.
    	LinearLayout searchRoot = (LinearLayout)menuItemSearch.getActionView();	// getActionView��searchRoot�擾.
    	Button closeButton = (Button)searchRoot.findViewById(R.id.search_close_button);	// closeButton�擾.
    	closeButton.setOnClickListener(new OnClickListener(){
    		@Override
    		public void onClick(View v){
    			Toast.makeText(mContext, "Close Clicked!", Toast.LENGTH_LONG).show();	// "Close Clicked!"��\��.
    		}
    	});
    	return true;
    	
    }
    
}