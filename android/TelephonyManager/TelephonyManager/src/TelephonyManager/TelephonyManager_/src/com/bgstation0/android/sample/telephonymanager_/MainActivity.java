package com.bgstation0.android.sample.telephonymanager_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.telephony.TelephonyManager;
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
				// TelephonyManager���擾.
				TelephonyManager telephonyManager = (TelephonyManager)mContext.getSystemService(TELEPHONY_SERVICE);	// telephonyManager���擾.
				// �d�b�ԍ����擾.
				String phoneNumber = telephonyManager.getLine1Number();	// telephonyManager.getLine1Number��phoneNumber���擾.
				Toast.makeText(mContext, "phoneNumber = " + phoneNumber, Toast.LENGTH_LONG).show();	// phoneNumber��\��.
			}
			
        });
        
    }
    
}