package com.bgstation0.android.sample.handler_;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

	// �����o�t�B�[���h�̒�`.
	private final String TAG = "Handler_";	// TAG"Handler_"�̒�`.
	private CustomHandler handler;	// CustomHandler�I�u�W�F�N�ghandler.

	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    
    	// �n���h���[�̏���.
    	handler = new CustomHandler(this);	// CustomHandler�I�u�W�F�N�ghandler�̃C���X�^���X����.(this��n��.)
    	
    	// �����N���X��Runnable����������Thread�𐶐����ĊJ�n.
    	new Thread(new Runnable(){	// Thread�I�u�W�F�N�g�𐶐�, ������Runnable���p�����������N���X�I�u�W�F�N�g��n��.(�g���̂ĂȂ�Q�Ƃ�ϐ��Ɋi�[���Ȃ��Ă���.)
    		public void run(){	// Runnable.run���I�[�o�[���C�h.
    			// 10�b��������Button1�̃e�L�X�g��"Pushed!"�ɕς���.
    			try{
    	    		Thread.sleep(10000);	// Thread.sleep��10�b�x�~.
    	    		//Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
    	    		//button1.setText("Pushed!");	// button1.setText��"Pushed!"�ɕύX.
    	    		handler.post();	// CustomHandler.post�̎��s.
    			}
    	    	catch(Exception ex){
    	    		Log.d(TAG, "ex = " + ex.toString());	// Log.d��ex���o��.
    	    	}
    		}
    	}).start();	// start�ŊJ�n.
    }
}
