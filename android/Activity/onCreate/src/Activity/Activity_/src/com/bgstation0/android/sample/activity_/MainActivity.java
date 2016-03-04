package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

	// �^�O�̒�`
	private final String TAG = "MainActivity";	// TAG��"MainActivity"
	
	// Activity���������ꂽ�Ƃ�.
    @Override
    protected void onCreate(Bundle savedInstanceState) {	// onCreate�̒�`
    	
    	// �e�N���X�̏�����, activity_main�̕\��.
        super.onCreate(savedInstanceState);	// super.onCreate�Őe�N���X�̊��菈��.
        setContentView(R.layout.activity_main);	// setContentView��R.layout.activity_main��\��.
        
        // onCreate�̃��O��\��.
        Log.v(TAG, "onCreate()");	// Log.v��"onCreate()"�Əo��.   
    }
    
    // Activity���J�n���ꂽ�Ƃ�.
    protected void onStart() {	// onStart�̒�`
    	
    	// �e�N���X�̏���
    	super.onStart();	// super.onStart�Őe�N���X�̊��菈��.
    	
    	// onStart�̃��O��\��.
    	Log.v(TAG, "onStart()");	// Log.v��"onStart()"�Əo��.
    }
    
    // Activity���\�������Ƃ�.
    protected void onResume() {	// onResume�̒�`
    	
    	// �e�N���X�̏���
    	super.onResume();	// super.onResume�Őe�N���X�̊��菈��.
    	
    	// onResume�̃��O��\��.
    	Log.v(TAG, "onResume()");	// Log.v��"onResume()"�Əo��.
    }
}
