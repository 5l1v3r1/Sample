package com.bgstation0.android.sample.aaa_;

import android.accounts.Account;
import android.accounts.AccountManager;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null�ŏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContext�̏�����.
        mContext = this;	// mContext��this�ŏ�����.
        
        // �A�J�E���g���ƃp�X���[�h�̎擾.
        final EditText etName = (EditText)findViewById(R.id.edittext1);	// etName���擾.
        final EditText etPassword = (EditText)findViewById(R.id.edittext2);	// etPassword���擾.
        Button button = (Button)findViewById(R.id.button1);	// button���擾.
        button.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				String name = etName.getText().toString();	// name���擾.
				String password = etPassword.getText().toString();	// password���擾.
				// �A�J�E���g�̕ۑ�.
				Account account = new Account(name, "com.bgstation0.android.sample");	// account����.
				AccountManager accountManager = AccountManager.get(mContext);	// accountManager���擾.
				accountManager.addAccountExplicitly(account, password, null);	// addAccountExplicitly�ŕۑ�.
				// �F�؉�ʂ����.
				setResult(RESULT_OK);	// RESULT_OK
				finish();	// �I��.
			}
			
		});
        
    }
    
}