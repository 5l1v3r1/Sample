package com.bgstation0.android.sample.context_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

	// �^�O�̒�`
	private final String TAG = "MainActivity";	// TAG��"MainActivity"
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Toast��this�̓��e�𕶎���ɂ������̂�\��.
     	Toast.makeText(this, this.toString(), Toast.LENGTH_LONG).show();
     		
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
        
        // button2���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewById��R.id.button2���擾.
        button2.setOnClickListener(this);	// button2.setOnClickListener��this(���g)���Z�b�g.
        
        // button3���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button3 = (Button)findViewById(R.id.button3);	// findViewById��R.id.button3���擾.
        button3.setOnClickListener(this);	// button3.setOnClickListener��this(���g)���Z�b�g.
        
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    	
    	// switch-case���ŐU�蕪����.
    	switch (v.getId()){	// v.getId��id���擾��, id���ƂɐU�蕪����.
    		
    		// button1
    		case R.id.button1:
    			
    			// �A�N�e�B�r�e�B�̊J�n.
    	    	Intent intent1 = new Intent(this, SubActivity.class);	// SubActivity��ΏۂƂ���Intent�I�u�W�F�N�gintent1�𐶐�.
    	    	startActivity(intent1);	// startActivity��intent1���w�肵��Activity���N��.
    			break;	// break�Ŕ�����.
    	
    		// button2
    		case R.id.button2:
    			
    			// �T�[�r�X�̊J�n.
    			Intent intent2 = new Intent(this, SubService.class);	// SubService��ΏۂƂ���Intent�I�u�W�F�N�gintent2�𐶐�.
    			startService(intent2);	// startService��intent2���w�肵��Service���N��.
    			Log.v(TAG, "startService(SubService)");	// Log.v��"startService(SubService)"�ƕ\��.
    			break;	// break�Ŕ�����.
    			
    		// button3
    		case R.id.button3:
    			
    			// �T�[�r�X�̒�~.
    			Intent intent3 = new Intent(this, SubService.class);	// SubService��ΏۂƂ���Intent�I�u�W�F�N�gintent3�𐶐�.
    			stopService(intent3);	// stopService��intent3���w�肵��Service���~.
    			Log.v(TAG, "stopService(SubService)");	// Log.v��"stopService(SubService)"�ƕ\��.
    			break;	// break�Ŕ�����.
    			
    	}
    	
    }

}
