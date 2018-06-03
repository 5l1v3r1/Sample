package com.bgstation0.android.sample.textview_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.inputmethod.EditorInfo;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null�ŏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContext��this���Z�b�g.
        mContext = this;
        
        // EditText�̃L�[���̓A�N�V�����J�X�^�}�C�Y.
        final EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1���擾.
        edittext1.setOnEditorActionListener(new TextView.OnEditorActionListener() {
			
			@Override
			public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
				// TODO Auto-generated method stub
				
				// Enter�L�[(Done)�������ꂽ��.
				if (actionId == EditorInfo.IME_ACTION_DONE){	// IME_ACTION_DONE�̎�.
					
					// ���͂��ꂽ�e�L�X�g��\��.
					Toast.makeText(mContext, edittext1.getText().toString(), Toast.LENGTH_LONG).show();	// edittext1.getText().toString()�Ŏ擾�����e�L�X�g��\��.
					return true;	// true��Ԃ�.
				
				}
				
				// false.
				return false;	// false��Ԃ�.
				
			}
			
		});
        
    }
    
}