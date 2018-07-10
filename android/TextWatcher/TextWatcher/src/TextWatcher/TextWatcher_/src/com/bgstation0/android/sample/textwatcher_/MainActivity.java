package com.bgstation0.android.sample.textwatcher_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements TextWatcher{

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null�ŏ�����.
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContext��this���Z�b�g.
        mContext = this;
        
        // EditText�̓��͕�����ɑ΂���A�N�V����.
        final EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1���擾.
        edittext1.addTextChangedListener(this);	// this���Z�b�g.
        
    }
    
 // �ω�����O.
	@Override
	public void beforeTextChanged(CharSequence s, int start, int count, int after) {
		
		// Toast�\��.
		Toast.makeText(mContext, "before: " + s, Toast.LENGTH_LONG).show();	// s��\��.
		
	}
	
	// �ω�������.
	@Override
	public void onTextChanged(CharSequence s, int start, int before, int count) {
		
		// Toast�\��.
		MainActivity mainActivity = (MainActivity)mContext;	// mainActivty���擾.
		final TextView textview1 = (TextView)mainActivity.findViewById(R.id.textview1);	// textview1���擾.
		textview1.setText(s);	// s���Z�b�g.
		
	}
	
	// �ω�������.
	@Override
	public void afterTextChanged(Editable s) {
		
		// Toast�\��.
		Toast.makeText(mContext, "after: " + s, Toast.LENGTH_LONG).show();	// s��\��.
		
	}
    
}
