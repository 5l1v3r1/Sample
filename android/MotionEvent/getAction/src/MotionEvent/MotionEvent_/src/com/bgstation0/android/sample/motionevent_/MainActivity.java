package com.bgstation0.android.sample.motionevent_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // �^�b�`�C�x���g������������.
    @Override
    public boolean onTouchEvent(MotionEvent event){
    
    	// �C�x���g�̃`�F�b�N.
    	int action = event.getAction();	// event.getAction��action���擾.
    	if (action == MotionEvent.ACTION_DOWN){	// �����ꂽ��.
    		Toast.makeText(this, "ACTION_DOWN", Toast.LENGTH_LONG).show();	// "ACTION_DOWN"�ƕ\��.
    	}
    	else if (action == MotionEvent.ACTION_MOVE){	// �������܂܈ړ�������.
    		Toast.makeText(this, "ACTION_MOVE", Toast.LENGTH_LONG).show();	// "ACTION_MOVE"�ƕ\��.
    	}
    	else if (action == MotionEvent.ACTION_UP){	// �w�𗣂�����.
    		Toast.makeText(this, "ACTION_UP", Toast.LENGTH_LONG).show();	// "ACTION_UP"�ƕ\��.
    	}
    	
        return true;	// ���������̂�true��Ԃ�.
        
    }
    
}
