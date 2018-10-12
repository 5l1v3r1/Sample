package com.bgstation0.android.sample.audiomanager_;

import android.app.Activity;
import android.content.Context;
import android.media.AudioManager;
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
				// AudioManager�̎擾.
				AudioManager audioManager = (AudioManager)mContext.getSystemService(AUDIO_SERVICE);	// audioManager���擾.
				int vol = audioManager.getStreamVolume(AudioManager.STREAM_MUSIC);	// ���y�̃{�����[�����擾.
				Toast.makeText(mContext, "vol = " + String.valueOf(vol), Toast.LENGTH_LONG).show();	// vol�̒l��\��.
			}
			
        });
        
    }
    
}