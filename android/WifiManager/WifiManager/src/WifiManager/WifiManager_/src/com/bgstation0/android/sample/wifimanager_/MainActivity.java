package com.bgstation0.android.sample.wifimanager_;

import android.app.Activity;
import android.content.Context;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
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
				// WifiManager�̎擾.
				WifiManager wifiManager = (WifiManager)mContext.getSystemService(WIFI_SERVICE);	// wifiManager���擾.
				// WifiInfo�̎擾.
				WifiInfo wifiInfo = wifiManager.getConnectionInfo();	// wifiInfo���擾.
				// ssid�擾.
				String ssid = wifiInfo.getSSID();	// ssid���擾.
				Toast.makeText(mContext, "ssid = " + ssid, Toast.LENGTH_LONG).show();	// ssid��\��.
			}
			
        });
        
    }
    
}