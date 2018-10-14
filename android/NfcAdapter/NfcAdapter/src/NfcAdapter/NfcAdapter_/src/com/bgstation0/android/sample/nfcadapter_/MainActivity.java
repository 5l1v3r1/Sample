package com.bgstation0.android.sample.nfcadapter_;

import android.app.Activity;
import android.content.Context;
import android.nfc.NfcAdapter;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null�ŏ�����.
		
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContext�̏�����.
        mContext = this;	// mContext��this���Z�b�g.
        
        // button1�̏�����.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				// NfcAdapter�̎擾.
				NfcAdapter nfcAdapter = NfcAdapter.getDefaultAdapter();	// nfcAdapter�̎擾.
				if (nfcAdapter != null){	// null�ł͂Ȃ�.
					if (nfcAdapter.isEnabled()){	// �g�p�\.
						Toast.makeText(mContext, "Nfc Enabled!", Toast.LENGTH_LONG).show();	// "Nfc Enabled!".
					}
					else{	// �g�p�s��.
						Toast.makeText(mContext, "Nfc Disabled!", Toast.LENGTH_LONG).show();	// "Nfc Disabled!".
					}
				}
				else{	// null�Ȃ�T�|�[�g����Ă��Ȃ�.
					Toast.makeText(mContext, "Nfc Not Support!", Toast.LENGTH_LONG).show();	// "Nfc Not Support!".
				}
			}
			
        });
        
    }
    
}