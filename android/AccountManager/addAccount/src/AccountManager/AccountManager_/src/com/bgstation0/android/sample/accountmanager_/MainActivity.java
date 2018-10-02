package com.bgstation0.android.sample.accountmanager_;

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
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null�ŏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    
        // mContext�̏�����.
        mContext = this;	// mContext��this���Z�b�g.
        
        // button1�̎擾.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(this);	// ���X�i�[��this���Z�b�g.
        
    }
    
    // �N���b�N���ꂽ��.
 	@Override
 	public void onClick(View v) {	// onClick�̒�`(�I�[�o�[���C�h)
 		// TODO Auto-generated method stub
 		AccountManager accountManager = AccountManager.get(this);	// accountManager�擾.
 		accountManager.addAccount("com.google", "mail", null, null, this, new AccountManagerCallback<Bundle>(){

			@Override
			public void run(AccountManagerFuture<Bundle> future) {
				// TODO Auto-generated method stub
				try{
					Bundle bundle = future.getResult();	// bundle���擾.
					String name = bundle.getString(AccountManager.KEY_ACCOUNT_NAME);
					Toast.makeText(mContext, "add name = " + name, Toast.LENGTH_LONG).show();	// �ǉ�����name��\��.
				}
				catch (Exception ex){
					Toast.makeText(mContext, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// ex��\��.
				}
			}
 			
 		}, null);	// �A�J�E���g�̒ǉ�.
 	}
    
}