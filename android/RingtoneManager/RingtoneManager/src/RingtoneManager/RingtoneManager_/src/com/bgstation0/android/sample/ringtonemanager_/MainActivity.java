package com.bgstation0.android.sample.ringtonemanager_;

import android.app.Activity;
import android.content.Context;
import android.media.Ringtone;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

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
				// �f�t�H���g��URI���擾.
				Uri uri = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_RINGTONE);	// �f�t�H���g��uri���擾.
				// ���M���擾.
				Ringtone ringtone = RingtoneManager.getRingtone(mContext, uri);	// ringtone���擾.
				// ���M���Đ�.
				ringtone.play();	// ringtone.play�ōĐ�.
			}
			
        });
        
    }
    
}