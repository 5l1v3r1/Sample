package com.bgstation0.android.sample.accountmanager_;

import android.accounts.AccountManager;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1�̎擾.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(this);	// ���X�i�[��this���Z�b�g.
        
    }
    
    // �N���b�N���ꂽ��.
 	@Override
 	public void onClick(View v) {	// onClick�̒�`(�I�[�o�[���C�h)
 		// TODO Auto-generated method stub
 		AccountManager accountManager = AccountManager.get(this);	// accountManager�擾.
 		Intent intent = accountManager.newChooseAccountIntent(null, null, new String[]{"com.google"}, false, null, null, null, null);	// �A�J�E���g�I���_�C�A���O�̃C���e���g�擾.
 		startActivityForResult(intent, 101);	// intent���N��.
 	}
 	
 	// �A�N�e�B�r�e�B�̌��ʂ��Ԃ��Ă����Ƃ�.
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
    	
    	// ���ʂɑ΂��鏈��.
    	super.onActivityResult(requestCode, resultCode, data);	// �܂��e�N���XonActivityResult
    	
    	// 101��OK�̏ꍇ.
    	if (requestCode == 101 && resultCode == Activity.RESULT_OK){
    		String name = data.getStringExtra(AccountManager.KEY_ACCOUNT_NAME);	// name���擾.
    		Toast.makeText(this, "name = " + name, Toast.LENGTH_LONG).show();	// name��\��.
    	}
    	
    }
    
}