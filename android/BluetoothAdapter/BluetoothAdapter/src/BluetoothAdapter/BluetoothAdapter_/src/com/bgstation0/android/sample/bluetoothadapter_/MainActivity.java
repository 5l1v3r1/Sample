package com.bgstation0.android.sample.bluetoothadapter_;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.content.Context;
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
				// BluetoothAdapter�̎擾.
				BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();	// bluetoothAdapter�̎擾.
				if (bluetoothAdapter != null){	// null�łȂ�.
					if (bluetoothAdapter.isEnabled()){	// �g�p�\.
						Toast.makeText(mContext, "Bluetooth Enabled!", Toast.LENGTH_LONG).show();	// "Bluetooth Enabled!".
					}
					else{	// �g�p�s��.
						Toast.makeText(mContext, "Bluetooth Disabled!", Toast.LENGTH_LONG).show();	// "Bluetooth Disabled!".
					}
				}
				else{	// null�Ȃ�T�|�[�g����Ă��Ȃ�.
					Toast.makeText(mContext, "Bluetooth Not Support!", Toast.LENGTH_LONG).show();	// "Bluetooth Not Support!".
				}
			}
			
        });
        
    }
    
}