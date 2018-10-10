package com.bgstation0.android.sample.notificationmanager_;

import android.app.Activity;
import android.app.Notification;
import android.app.NotificationManager;
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
	NotificationManager mNotificationManager = null;	// mNotificationManager��null�ŏ�����.
	int mNumber = 0;	// mNumber��0�ŏ�����.
	Context mContext = null;	// mContext��null�ŏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContext�̏�����.
        mContext = this;	// mContext��this���Z�b�g.
        
        // NotificationManager�̎擾.
        mNotificationManager = (NotificationManager)getSystemService(NOTIFICATION_SERVICE);	// mNotificationManager���擾.

        // button1�̏�����.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				if (v.getId() == R.id.button1){
					// Notification�𐶐�.
					Notification notification = new Notification();	// notification�𐶐�.
					notification.tickerText = "NotificationManager";	// �`�P�b�g�e�L�X�g��"NotificationManager".
					notification.icon = R.drawable.ic_launcher;	// �A�C�R����ic_launcher.
					notification.number = mNumber;	// mNumber���Z�b�g.
					notification.setLatestEventInfo(getApplicationContext(), "NotificationManager", "notify", null);	// �C�x���g.(���ꂪ�Ȃ��Ɨ�����.������deprecate����Ă�.����͎��s����intent���w�肵�Ȃ�.)
					mNotificationManager.notify(mNumber, notification);	// mNotificationManager.notify�Œʒm.
					mNumber++;	// mNumber�𑝂₷.					
				}
			}
		});
        
    }
    
}