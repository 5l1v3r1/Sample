package com.bgstation0.android.sample.cursoradapter_;

import android.app.Activity;
import android.app.SearchManager;
import android.app.SearchableInfo;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.provider.SearchRecentSuggestions;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.inputmethod.EditorInfo;
import android.widget.AutoCompleteTextView;
import android.widget.TextView;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null���Z�b�g.
	CustomCursorAdapter mAdapter = null;	// mAdapter��null���Z�b�g.
	SearchRecentSuggestions mSuggestions = null;	// mSuggestions��null���Z�b�g.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �R���e�L�X�g�̃Z�b�g.
        mContext = this;	// mContext��this���Z�b�g.
        
        // AutoCompleteTextView�̎擾.
        final AutoCompleteTextView autoCompleteTextView = (AutoCompleteTextView)findViewById(R.id.autocompletetextview1);	// autoCompleteTextView���擾.
        
        // SearchManager�̎擾.
        SearchManager searchManager = (SearchManager)getSystemService(Context.SEARCH_SERVICE);	// searchManager�̎擾.
        
        // SearchableInfo�̎擾.
        SearchableInfo searchableInfo = (SearchableInfo)searchManager.getSearchableInfo(getComponentName());	// searchableInfo�̎擾.
        
        // CustomCursorAdapter�̃Z�b�g.
        mAdapter = new CustomCursorAdapter(this, true, searchableInfo);	// mAdapter�̐���.
        autoCompleteTextView.setAdapter(mAdapter);	// autoCompleteTextView�ɃZ�b�g.
    
        // SearchRecentSuggestions�̐���.
        mSuggestions = new SearchRecentSuggestions(mContext, CustomContentProvider.AUTHORITY, CustomContentProvider.MODE);	// SearchRecentSuggestions�I�u�W�F�N�gmSuggestions�̐���.
        
        // �G�f�B�^�[�A�N�V����.
        autoCompleteTextView.setOnEditorActionListener(new TextView.OnEditorActionListener() {
			
			@Override
			public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
				
				// TODO Auto-generated method stub
				// Enter�L�[(Done)�������ꂽ��.
				if (actionId == EditorInfo.IME_ACTION_DONE){	// IME_ACTION_DONE�̎�.
					
					// �N�G���̓o�^.
        			String query = autoCompleteTextView.getText().toString();	// query���擾.
        			mSuggestions.saveRecentQuery(query, null);	// mSuggestions.saveRecentQuery�ŃN�G����ۑ�.
        			return true;	// true��Ԃ�.
				
				}
				
				// false.
				return false;	// false��Ԃ�.
				
			}
			
        });
        
    }
    
    // Activity���j�����ꂽ�Ƃ�.
    protected void onDestroy() {	// onDestroy�̒�`
    	
    	// �e�N���X�̏���
    	super.onDestroy();	// super.onDestroy�Őe�N���X�̊��菈��.
    	
    	// �A�_�v�^�����.
    	mAdapter.close();	// mAdapter.close�ŕ���.
    	
    }
    
}