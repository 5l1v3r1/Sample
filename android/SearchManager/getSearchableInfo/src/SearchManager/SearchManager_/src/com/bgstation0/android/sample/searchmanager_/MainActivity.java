package com.bgstation0.android.sample.searchmanager_;

import android.app.Activity;
import android.app.SearchManager;
import android.app.SearchableInfo;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.InputType;
import android.view.Menu;
import android.view.MenuItem;
import android.view.inputmethod.EditorInfo;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // SearchManager�̎擾.
        SearchManager searchManager = (SearchManager)getSystemService(Context.SEARCH_SERVICE);	// searchManager���擾.
        SearchableInfo searchableInfo = searchManager.getSearchableInfo(getComponentName());	// searchManager.getSearchableInfo��searchableInfo���擾.
        
        // SearchableInfo�̎擾.
        Toast.makeText(this, "hint = " + getString(searchableInfo.getHintId()), Toast.LENGTH_LONG).show();	// searchableInfo.getHintId()�Ŏ擾����hint��ID����hint�̕�������擾���ĕ\��.
        int inputType = searchableInfo.getInputType();	// searchableInfo.getInputType()�œ��̓^�C�v���擾.
        if (inputType == InputType.TYPE_CLASS_TEXT){	// TYPE_CLASS_TEXT�Ȃ�.
        	Toast.makeText(this, "inputType = TYPE_CLASS_TEXT", Toast.LENGTH_LONG).show();	// "inputType = TYPE_CLASS_TEXT"��\��.
        }
        int imeOptions = searchableInfo.getImeOptions();	// searchableInfo.getImeOptions()��IME�I�v�V�������擾.
        if (imeOptions == EditorInfo.IME_ACTION_SEARCH){	// IME_ACTION_SEARCH�Ȃ�.
        	Toast.makeText(this, "imeOptions = IME_ACTION_SEARCH", Toast.LENGTH_LONG).show();	// "imeOptions = IME_ACTION_SEARCH"��\��.
        }
        
        // �����_�C�A���O�\��.
        onSearchRequested();	// �e�N���X��onSearchRequested���Ă�.
        
    }
    
    @Override
    protected void onNewIntent(Intent intent){
    	
    	super.onNewIntent(intent);
    	
    	// �����N�G���̎擾.
        if (intent != null){	// intent��null�łȂ���.
        	String action = intent.getAction();	// action���擾.
        	if (action != null){	// action��null�łȂ���.
        		if (action.equals(Intent.ACTION_SEARCH)){	// action��Intent.ACTION_SEARCH�̎�.
        			String query = intent.getStringExtra(SearchManager.QUERY);	// query���擾.
        			Toast.makeText(this, "query = " + query, Toast.LENGTH_LONG).show();	// query��\��.
        		}
        	}
        }
        
    }
    
}