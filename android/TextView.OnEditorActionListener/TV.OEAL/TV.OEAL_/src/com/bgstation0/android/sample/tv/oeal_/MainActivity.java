package com.bgstation0.android.sample.tv.oeal_;

import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.inputmethod.EditorInfo;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;
import android.widget.Toast;

public class MainActivity extends Activity implements OnEditorActionListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // EditText�̃L�[���̓A�N�V�����J�X�^�}�C�Y.
        EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1���擾.
        edittext1.setOnEditorActionListener(this);	// this��n��.
    
    }
    
    @Override
	public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {

		// Enter�L�[(Go)�������ꂽ��.
		if (actionId == EditorInfo.IME_ACTION_GO){	// IME_ACTION_GO�̎�.
			
			// ���͂��ꂽ�e�L�X�g��\��.
			Toast.makeText(this, v.getText().toString(), Toast.LENGTH_LONG).show();	// v.getText().toString()�Ŏ擾�����e�L�X�g��\��.
			return true;	// true��Ԃ�.
		
		}
		
		// false.
		return false;	// false��Ԃ�.
		
	}
    
}