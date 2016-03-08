package com.bgstation0.android.sample.service_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

	// �^�O�̒�`
	private final String TAG = "MainActivity";	// TAG��"MainActivity"

	// Activity���������ꂽ�Ƃ�.
    @Override
    protected void onCreate(Bundle savedInstanceState) {	// onCreate�̒�`
    	
    	// �e�N���X�̏�����, activity_main�̕\��.
        super.onCreate(savedInstanceState);	// super.onCreate�Őe�N���X�̊��菈��.
        setContentView(R.layout.activity_main);	// setContentView��R.layout.activity_main��\��.
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
        
        // button2���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewById��R.id.button2���擾.
        button2.setOnClickListener(this);	// button2.setOnClickListener��this(���g)���Z�b�g.
        
        // onCreate�̃��O��\��.
        Log.v(TAG, "onCreate()");	// Log.v��"onCreate()"�Əo��.
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    	
    	// switch-case���ŐU�蕪����.
    	switch (v.getId()){	// v.getId��id���擾��, id���ƂɐU�蕪����.
    		
    		// button1
    		case R.id.button1:
    			
    			// �T�[�r�X�̊J�n
    			Intent intent1 = new Intent(this, MainService.class);	// MainService��ΏۂƂ���Intent�I�u�W�F�N�gintent1�𐶐�.
    			startService(intent1);	// startService��intent1���w�肵��Service���N��.
    			Log.v(TAG, "startService(MainService)");	// Log.v��"startService(MainService)"�ƕ\��.
    			break;	// break�Ŕ�����.
    			
    		// button2
    		case R.id.button2:

    			// �T�[�r�X�̊J�n
    			Intent intent2 = new Intent(this, MainService.class);	// MainService��ΏۂƂ���Intent�I�u�W�F�N�gintent2�𐶐�.
    			stopService(intent2);	// stopService��intent2���w�肵��Service���~.
    			Log.v(TAG, "stopService(MainService)");	// Log.v��"stopService(MainService)"�ƕ\��.
    			break;	// break�Ŕ�����.
    			
    	}
    }
}
