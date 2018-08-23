package com.bgstation0.android.sample.view_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null���Z�b�g.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContext�̎擾.
        mContext = this;	// mContext��this���Z�b�g.
        
        // edittext1�̎擾.
        EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1���擾.
        
        // �t�H�[�J�X���X�i�[�̃Z�b�g.
        edittext1.setOnFocusChangeListener(new View.OnFocusChangeListener() {
			
			@Override
			public void onFocusChange(View v, boolean hasFocus) {
				// TODO Auto-generated method stub
				
				// �t�H�[�J�X��Ԃ�\��.
				Toast.makeText(mContext, "hasFocus = " + String.valueOf(hasFocus), Toast.LENGTH_LONG).show();	// hasFocus��\��.
				
			}
			
		});
        
    }
    
}