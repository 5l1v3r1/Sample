package com.bgstation0.android.sample.localactivitymanager_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Toast;

public class SubActivity extends Activity {

	// Activity���쐬���ꂽ��.
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub);
        
        // "onCreate"�̕\��.
        Toast.makeText(this, "onCreate", Toast.LENGTH_LONG).show();	// Toast��"onCreate"��\��.
        
	}
	
	// Activity���j�����ꂽ�Ƃ�.
    protected void onDestroy() {	// onDestroy�̒�`
    	
    	// �e�N���X�̏���
    	super.onDestroy();	// super.onDestroy�Őe�N���X�̊��菈��.
    	
    	// "onDestroy"�̕\��.
        Toast.makeText(this, "onDestroy", Toast.LENGTH_LONG).show();	// Toast��"onDestroy"��\��.
        
    }
	
}