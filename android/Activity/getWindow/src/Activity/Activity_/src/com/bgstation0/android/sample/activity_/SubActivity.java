package com.bgstation0.android.sample.activity_;

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

        // "onCreate"��tag�̕\��.
        Intent intent = getIntent();	// intent���擾.
        String tag = intent.getStringExtra("tag");	// "tag"�̒l���擾.
        //Toast.makeText(this, "onCreate(" + tag + ")", Toast.LENGTH_LONG).show();	// Toast��"onCreate"��tag��\��.
        Toast.makeText(this, tag + ": " + getWindow().toString(), Toast.LENGTH_LONG).show();	// tag��getWindow().toString()���o��.
        
	}
	
	// Activity���J�n���ꂽ�Ƃ�.
	@Override
    protected void onStart(){
    	super.onStart();
    	
    	// "onStart"��tag�̕\��.
        Intent intent = getIntent();	// intent���擾.
        String tag = intent.getStringExtra("tag");	// "tag"�̒l���擾.
        //Toast.makeText(this, "onStart(" + tag + ")", Toast.LENGTH_LONG).show();	// Toast��"onStart"��tag��\��.
        Toast.makeText(this, tag + ": " + getWindow().toString(), Toast.LENGTH_LONG).show();	// tag��getWindow().toString()���o��.
        
    }
	
	// Activity���j�����ꂽ�Ƃ�.
	@Override
    protected void onDestroy() {	// onDestroy�̒�`
    	
    	// �e�N���X�̏���
    	super.onDestroy();	// super.onDestroy�Őe�N���X�̊��菈��.
    	
    	// "onDestroy"�̕\��.
        //Toast.makeText(this, "onDestroy", Toast.LENGTH_LONG).show();	// Toast��"onDestroy"��\��.
        
    }
    
    @Override
    protected void onNewIntent(Intent intent){
    	super.onNewIntent(intent);
    	
    	// "onNewIntent"��tag�̕\��.
        String tag = intent.getStringExtra("tag");	// "tag"�̒l���擾.
        //Toast.makeText(this, "onNewIntent(" + tag + ")", Toast.LENGTH_LONG).show();	// Toast��"onNewIntent"��tag��\��.
        
    }
	
}