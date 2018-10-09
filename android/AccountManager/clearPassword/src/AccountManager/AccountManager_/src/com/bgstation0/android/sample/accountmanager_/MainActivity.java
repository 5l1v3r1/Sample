package com.bgstation0.android.sample.accountmanager_;

import android.accounts.Account;
import android.accounts.AccountManager;
import android.accounts.AccountManagerCallback;
import android.accounts.AccountManagerFuture;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null�ŏ�����.
	String mToken = "";	// mToken��""�ŏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    
        // mContext�̏�����.
        mContext = this;	// mContext��this���Z�b�g.
        
        // button1�̎擾.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(this);	// ���X�i�[��this���Z�b�g.
        // button2�̎擾.
        Button button2 = (Button)findViewById(R.id.button2);	// button2���擾.
        button2.setOnClickListener(this);	// ���X�i�[��this���Z�b�g.
        // button3�̎擾.
        Button button3 = (Button)findViewById(R.id.button3);	// button3���K��.
        button3.setOnClickListener(this);	// ���X�i�[��this���Z�b�g.
        
    }
    
    // �N���b�N���ꂽ��.
 	@Override
 	public void onClick(View v) {	// onClick�̒�`(�I�[�o�[���C�h)
 		// TODO Auto-generated method stub
 		if (v.getId() == R.id.button1){	// button1�������ꂽ��.
	 		AccountManager accountManager = AccountManager.get(this);	// accountManager�擾.
	 		EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1���擾.
	 		Account target = new Account(edittext1.getText().toString(), "com.google");	// target�𐶐�.
	 		accountManager.getAuthToken(target, "mail", null, this, new AccountManagerCallback<Bundle>(){
	
				@Override
				public void run(AccountManagerFuture<Bundle> future) {
					// TODO Auto-generated method stub
					try{
						Bundle bundle = future.getResult();	// bundle���擾.
						mToken = bundle.getString(AccountManager.KEY_AUTHTOKEN);	// token���擾.
						Toast.makeText(mContext, "token = " + mToken, Toast.LENGTH_LONG).show();	// mToken��\��.
					}
					catch (Exception ex){
						Toast.makeText(mContext, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// ex��\��.
					}
				}
			
	 		}, null);	// �g�[�N���̎擾.
 		}
 		else if (v.getId() == R.id.button2){	// button2�������ꂽ��.
 			AccountManager accountManager = AccountManager.get(this);	// accountManager�擾.
 			accountManager.invalidateAuthToken("com.google", mToken);	// mToken�𖳌��ɂ���.
 			Toast.makeText(mContext, "invalidate token = " + mToken, Toast.LENGTH_LONG).show();	// ���������ꂽ���Ƃ�\��.
 		}
 		else if (v.getId() == R.id.button3){	// button3�̉����ꂽ��.
 			AccountManager accountManager = AccountManager.get(this);	// accountManager�擾.
 			EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1���擾.
 			Account target = new Account(edittext1.getText().toString(), "com.google");	// target�𐶐�.
 			accountManager.clearPassword(target);	// �p�X���[�h���N���A���邱�ƂŃA�J�E���g�𖳌���.
 		}
 		
 	}
 	
}