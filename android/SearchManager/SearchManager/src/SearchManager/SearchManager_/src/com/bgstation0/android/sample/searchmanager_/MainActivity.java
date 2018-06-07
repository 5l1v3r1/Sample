package com.bgstation0.android.sample.searchmanager_;

import android.app.Activity;
import android.app.SearchManager;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // SearchManager�̎擾.
        SearchManager searchManager = (SearchManager)getSystemService(Context.SEARCH_SERVICE);	// searchManager���擾.
        
        // �V�X�e�����ʂ̌����_�C�A���O��\��.
        searchManager.startSearch("ABC", false, getComponentName(), null, false);	// searchManager.startSearch�Ō����_�C�A���O��\��.
        
    }
    
}