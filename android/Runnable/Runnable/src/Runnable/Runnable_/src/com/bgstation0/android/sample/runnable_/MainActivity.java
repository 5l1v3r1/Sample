package com.bgstation0.android.sample.runnable_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

	// �����o�t�B�[���h�̒�`.
	private final String TAG = "Runnable_";	// TAG"Runnable_"�̒�`.
	
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
    
    	// �����N���X��Runnable����������Thread�𐶐����ĊJ�n.
    	new Thread(new Runnable(){	// Thread�I�u�W�F�N�g�𐶐�, ������Runnable���p�����������N���X�I�u�W�F�N�g��n��.(�g���̂ĂȂ�Q�Ƃ�ϐ��Ɋi�[���Ȃ��Ă���.)
    		public void run(){	// Runnable.run���I�[�o�[���C�h.
    			try{
    	    		Log.d(TAG, "Thread.sleep before");	// Log.d��"Thread.sleep before"�ƃ��O�o��.
    	    		Thread.sleep(10000);	// Thread.sleep��10�b�x�~.
    	    		Log.d(TAG, "Thread.sleep after");	// Log.d��"Thread.sleep after"�ƃ��O�o��.
    	    	}
    	    	catch(Exception ex){
    	    		Log.d(TAG, "ex = " + ex.toString());	// Log.d��ex���o��.
    	    	}
    		}
    	}).start();	// start�ŊJ�n.
    	
    }
    
}
